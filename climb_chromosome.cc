#include "climb_chromosome.hh"
#include <random>

void ClimbChromosome::mutate() {
  int len = order_.size();
  int i = std::rand % len;  // randomized index

  // initial fitness
  double fit1 = get_fitness();
  Cities::permutation_t order1 = order_;  // store initial permutation

  // fitness with (i-1, i) swapped
  int idec;
  if (i>0) {
    idec = i-1;
  }
  else {
    idec = len-1;
  }
  Cities::permutation_t order2 = swap(order1, idec, i);
  order_ = order2;
  double fit2 = get_fitness();

  // fitness with (i, i+1) swapped
  int iinc = (i+1)*(idec<(len-1));
  Cities::permutation_t order3 = swap(order1, i, iinc);
  order_ = order3;
  double fit3 = get_fitness();

  // compare & return
  if ((fit1 >= fit2) && (fit1 >= fit3)) {
    order_ = order1;
  }
  if ((fit2 >= fit1) && (fit2 >= fit3)) {
    order_ = order2;
  }
}

Cities::permutation_t swap(Cities::permutation_t order, int i1, int i2) {
  int ival = order[i1];
  order[i1] = order[i2];
  order[i2] = ival;
  return order;
}
