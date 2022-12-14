#include "Column.hpp"

#include <cmath>

Column::Column() { name = "UNKNOWN"; };

Column::Column(std::string _name) { name = _name; }

bool Column::isType(Type type) {
  for (Value value : values) {
    if (value.type != type) {
      return false;
    }
  }

  return true;
}

double Column::sum() {
  if (!isType(NUMBER)) {
    return NAN;
  }

  double sum = 0.0;
  for (Value value : values) {
    sum += value.numberValue;
  }
  return sum;
}

double Column::mean() { return sum() / values.size(); }

std::string Column::toString() {
  std::string result = "[";

  bool first = true;

  for (Value value : values) {
    if (!first) {
      result = result + ",";
    }
    result = result + value.toString();
    first = false;
  }

  result = result + "]";

  return result;
}