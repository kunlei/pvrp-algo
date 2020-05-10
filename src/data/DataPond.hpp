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
  inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v") {
    s.erase(0, s.find_first_not_of(t));
    return s;
  }

  // trim from right
  inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v") {
    s.erase(s.find_last_not_of(t) + 1);
    return s;
  }

  // trim from left & right
  inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v") {
    return ltrim(rtrim(s, t), t);
  }

  

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