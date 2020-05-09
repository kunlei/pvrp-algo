#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <vector>

namespace pvrp {

class Customer {
 public:
  Customer();
  ~Customer();

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
   * demand
   */
  int demand;
  /**
   * service time
   */
  int srvTime;
  /**
   * 
   */
  std::vector<std::vector<int>> patterns;
};

}

#endif