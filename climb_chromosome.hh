#pragma once

#include "chromosome.hh"

class ClimbChromosome : public Chromosome::Chromosome {
  using Chromosome::Chromosome;

public:
  void mutate();

  ClimbChromosome* clone() const {
    return new ClimbChromosome(cities_ptr_);
  }
};
