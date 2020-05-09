#ifndef DATA_POND_HPP
#define DATA_POND_HPP
#include <vector>
#include <iostream>
#include "Customer.hpp"

namespace pvrp {

class DataPond {
 public:
  friend std::ostream &operator<<(std::ostream &, const DataPond &);

 public:
  DataPond();
  ~DataPond();

  // data processing
  void readData(std::string instId);
  void calDistance();
  void calSrvPattern();

  // accessors
  int getNumDays() const { return numDays; }
  int getNumVehicles() const { return numVehicles; }
  double getMaxDuration() const { return maxDuration; }
  int getMaxLoad() const { return maxLoad; }

 private:
  /**
   * number of days in the planning horizon
   */
  int numDays;
  /**
   * number of vehicles
   */
  int numVehicles;
  /**
   * constraints on the vehicle
   */
  double maxDuration;
  int maxLoad;
  /**
   * all the customers
   */
  std::vector<Customer> customers;
};
std::ostream &operator<<(std::ostream &, const DataPond &);

}
#endif