#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <vector>
#include <iostream>

namespace pvrp {

/**
 * define a customer class.
 * 
 * A customer object represents a location with demand to be fulfilled.
 * It is also associated with a service time required to perform the
 * service. 
 * 
 * A customer is also given a list of candidate service patterns that
 * indicates on which days it can be serviced.
 * 
 * Note that the customer with index 0 indicates the depot.
 */
class Customer {
 public:
  friend std::ostream &operator<<(std::ostream &, const Customer &c);

 public:
  Customer(int idx, double lat, double lon,
           double srvTime, int demand,
           int numPatterns);
  ~Customer();
  Customer() = delete;

  // accessors
  int getIdx() const { return idx; }
  double getLat() const { return lat; }
  double getLon() const { return lon; }
  double getSrvTime() const { return srvTime; }
  int getDemand() const { return demand; }

  // distance
  void initDistVec(int numCus);
  void setDist(int cusIdx, double dist) { distToOtherCus.at(cusIdx) = dist; }
  double getDist(int cusIdx) const { return distToOtherCus.at(cusIdx); }

  // service pattern
  void addPattern(int dayIdx, int val);
  int getNumPatterns() const { return numPatterns; }
  std::vector<bool> &getPattern(int pIdx) { return patterns.at(pIdx); }

 private:
  /**
   * unique index of this customer
   */
  int idx;
  /**
   * latitude and longitude
   */
  double lat;
  double lon;
  /**
   * distance to other customers
   */
  std::vector<double> distToOtherCus;
  /**
   * service time
   */
  int srvTime;
  /**
   * demand
   */
  int demand;
  /**
   * service patterns
   */
  int numPatterns;
  std::vector<std::vector<bool>> patterns;
};
std::ostream &operator<<(std::ostream &, const Customer &c);

}

#endif