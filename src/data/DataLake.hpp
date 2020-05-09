#ifndef DATA_LAKE_HPP
#define DATA_LAKE_HPP

namespace pvrp {

class Datalake {

 public:
  Datalake();
  ~Datalake();

  void readData();

 private:
  /**
   * number of days
   */
  int numDays;

};

}
#endif