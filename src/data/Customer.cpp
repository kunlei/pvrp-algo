#include "Customer.hpp"

namespace pvrp {

using std::ostream;
using std::vector;

/**
 * output to file/string/console
 */
ostream &operator<<(ostream &strm, const Customer &c) {
  strm << "Customer{idx: " << c.idx
       << "\tsrvTime: " << c.srvTime
       << "\tdemand: " << c.demand
       << "\tnumPatterns: " << c.numPatterns
       << "}";
  return strm;
}

/**
 * constructor
 */
Customer::Customer(int idx, double lat, double lon,
                   double srvTime, int demand,
                   int numPatterns) : idx(idx),
                                      lat(lat),
                                      lon(lon),
                                      srvTime(srvTime),
                                      demand(demand),
                                      numPatterns(numPatterns) {

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
void Customer::addPattern(int dayIdx, int val) {

}


}