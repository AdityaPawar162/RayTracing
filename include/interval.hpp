#ifndef INTERVAL_HPP
#define INTERVAL_HPP
#pragma once
class interval {
public:
  double min, max;

  interval() : min(+infinity), max(-infinity) {}

  interval(double _min, double _max) : min(_min), max(_max) {}

  bool contains(double x) const { return min <= x && x <= max; }

  bool surronds(double x) const { return min < x && x < max; }

  double clamps(double x) const {
    if(x < min) {return min; }
    if(x > max) {return max; } 

    EXIT_SUCCESS;
  }

  static const interval empty, universe;
};

const static interval empty(+infinity, -infinity);
const static interval universe(-infinity, +infinity);


#endif //! INTERVAL_HPP 
