#include <AscendingIterator.cpp>
AscendingIterator::AscendingIterator(const MagicalContainer& c) : container(c), it(c.elements.begin()) {}

AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), it(other.it) {}

AscendingIterator::~AscendingIterator() {}

AscendingIterator& AscendingIterator::operator=(const AscendingIterator& other){return null}

bool AscendingIterator::operator==(const AscendingIterator& other) const{return true}

bool AscendingIterator::operator!=(const AscendingIterator& other) const{return true}

bool AscendingIterator::operator>(const AscendingIterator& other) const{return true}

bool AscendingIterator::operator<(const AscendingIterator& other) const{return true}

int AscendingIterator::operator*() const{return 0}

AscendingIterator& AscendingIterator::operator++(){return null}

static AscendingIterator begin(const MagicalContainer& container){return null}

static AscendingIterator end(const MagicalContainer& container){return null}