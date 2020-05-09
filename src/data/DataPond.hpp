#ifndef DATA_POND_HPP
#define DATA_POND_HPP
#include <vector>
#include <string>
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
  void readData(std::string instMark, int instId);
  void calDistance();
  void calSrvPattern();

  // accessors
  int getNumVehicles() const { return numVehicles; }
  int getNumCustomers() const { return numCustomers; }
  int getNumDays() const { return numDays; }
  double getMaxDuration() const { return maxDuration; }
  int getMaxLoad() const { return maxLoad; }

 private:
  /**
   * number of vehicles
   */
  int numVehicles;
  /**
   * number of customers
   */
  int numCustomers;
  /**
   * number of days in the planning horizon
   */
  int numDays;
  /**
   * constraints on the vehicle
   */
  double maxDuration;
  int maxLoad;
  /**
   * all the customers
   */
  std::vector<Customer *> customers;
};
std::ostream &operator<<(std::ostream &, const DataPond &);

}
#endif