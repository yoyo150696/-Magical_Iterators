#include <PrimeIterator.hpp>

PrimeIterator::PrimeIterator(const MagicalContainer& c) : container(c), it(c.elements.begin()){}

PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container), it(other.it) {}

PrimeIterator::~PrimeIterator() {}

PrimeIterator::PrimeIterator& operator=(const PrimeIterator& other){return null}

bool PrimeIterator::operator==(const PrimeIterator& other) const{return true}

bool PrimeIterator::operator!=(const PrimeIterator& other) const{return true}

bool PrimeIterator::operator>(const PrimeIterator& other) const{return true}

bool PrimeIterator::operator<(const PrimeIterator& other) const{return true}

int PrimeIterator::operator*() const{return 0}

PrimeIterator& PrimeIterator::operator++(){return null}

static PrimeIterator begin(const MagicalContainer& container){return null}

static PrimeIterator end(const MagicalContainer& container){return null}

void findNextPrime(){}

bool isPrime(int num) const{return true}