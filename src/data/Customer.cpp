#include "Customer.hpp"
#include <iostream>
#include <cmath>

namespace pvrp {

using std::pow;
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

/**
 * output to file/string/console
 */
ostream &operator<<(ostream &strm, const Customer &c) {
  strm << "Customer{idx: " << c.idx
       << "\tsrvTime: " << c.srvTime
       << "\tdemand: " << c.demand
       << "\tsrvFreq: " << c.srvFreq
       << "\tnumPatterns: " << c.numPatterns
       << "}";
  return strm;
}

/**
 * constructor
 */
Customer::Customer(int idx, double lat, double lon,
                   double srvTime, int demand,
                   int srvFreq, int numPatterns,
                   int numDays) : idx(idx),
                                  lat(lat),
                                  lon(lon),
                                  srvTime(srvTime),
                                  demand(demand),
                                  srvFreq(srvFreq),
                                  numPatterns(numPatterns) {
  // initialize the vector of service patterns, with each pattern itself
  // a vector of size 'numDays' and a 'true' value indicate a day that
  // service is needed, false otherwise
  patterns.reserve(numPatterns);
  vector<bool> patt(numDays, false);
  for (int p = 0; p < numPatterns; ++p) {
    patterns.push_back(patt);
  }
}

/**
 * destructor
 */
Customer::~Customer() {

}

/**
 * initialize empty distance vector
 */
void Customer::initDistVec(int numCus) {
  distToOtherCus.reserve(numCus);
  for (int i = 0; i < numCus; ++i) {
    distToOtherCus.push_back(0);
  }
}

/**
 * add a candidate service pattern
 */
void Customer::addPattern(int pIdx, int val) {
  int binary = numToBinary(val);

  int base = (int) pow(10, 4 - 1);
  int quotient, remainder;
  for (int i = 0; i < 4; ++i) {
    quotient = binary / base;
    remainder = binary % base;
    patterns.at(pIdx).at(i) = quotient;
    binary = remainder;
    base = base / 10;
  }
}

int Customer::numToBinary(int num) {
  if (num == 0) {
    return 0;
  } else {
    return num % 2 + 10 * numToBinary(num / 2);
  }
}


}