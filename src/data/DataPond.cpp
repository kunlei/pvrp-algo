#include "DataPond.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace pvrp {

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ios;
using std::ifstream;
using std::stringstream;
using std::vector;
using std::stoi;
using std::stod;

/**
 * output to console/file/string
 */
ostream &operator<<(ostream &strm, const DataPond &dp) {
  strm << "DataPond{numVehicles: " << dp.numVehicles
       << "\tnumCustomers: " << dp.numCustomers
       << "\tnumDays: " << dp.numDays
       << "\tmaxDuration: " << dp.maxDuration
       << "\tmaxLoad: " << dp.maxLoad
       << "}";
  return strm;
}

/**
 * constructor
 */
DataPond::DataPond() : numVehicles(0),
                       numCustomers(0),
                       numDays(0),
                       maxDuration(0),
                       maxLoad(0) {

}

/**
 * destructor
 */
DataPond::~DataPond() {

}

/**
 * read instance data from file
 * @param instMark type of the instance, "new" or "old"
 * @param instId integer id of the instance
 */
void DataPond::readData(string instMark, int instId) {
  cout << "DataPond::start reading instance file...\n";
  // derive filename
  string filename = "instance/";
  if (instMark == "new") {
    filename += "new/pr";
    if (instId < 10) {
      filename += "0" + to_string(instId) + ".txt";
    } else {
      filename += to_string(instId) + ".txt";
    }
  } else if (instMark == "old") {
    filename += "old/p";
    if (instId < 10) {
      filename += "0" + to_string(instId) + ".txt";
    } else {
      filename += to_string(instId) + ".txt";
    }
  } else {
    cout << "DataPond::error in reading instance file, exit...\n";
    return;
  }
  cout << "\tfilename: " << filename << "\n";

  // create input file stream
  ifstream infile(filename, ios::in);
  
  string line, word;
  vector<string> row;

  // read first line
  getline(infile, line);
  stringstream s(line);
  while (getline(s, word, ' ')) {
    row.push_back(word);
  }
  numVehicles = stoi(row.at(1)); 
  numCustomers = stoi(row.at(2));
  numDays = stoi(row.at(3));

  // read constraints on vehicle
  for (int i = 0; i < numVehicles; ++i) {
    getline(infile, line);
    stringstream s(line);
    row.clear();
    while (getline(s, word, ' ')) {
      row.push_back(word);
    }
    maxDuration = stoi(row.at(0));
    maxLoad = stoi(row.at(1));
  }

  // read individual customers
  int idx;
  double lat, lon;
  int srvTime, demand;
  int srvFreq, numPattern, pattVal;
  int colIdx{0};
  while (getline(infile, line)) {
    getline(infile, line);
    stringstream s(line);
    row.clear();
    while (getline(s, word, ' ')) {
      row.push_back(word);
    }

    colIdx = 0;
    // read index
    idx = stoi(row.at(colIdx++));

    // latitude and longitude
    lat = stod(row.at(colIdx++));
    lon = stod(row.at(colIdx++));

    // service duration
    srvTime = stoi(row.at(colIdx++));
    demand = stoi(row.at(colIdx++));
    
    // pattern
    srvFreq = stoi(row.at(colIdx++));
    numPattern = stoi(row.at(colIdx++));

    Customer *pCus = new Customer(idx, lat, lon,
                                  srvTime, demand,
                                  numPattern, numDays);

    for (int p = 0; p < numPattern; ++p) {
      pattVal = stoi(row.at(colIdx + p));
      pCus->addPattern(p, pattVal);
    }

    customers.push_back(pCus);
  }

  infile.close();
  cout << "DataPond::start reading instance file...\n";
}
  
}