#include <SideCrossIterator>

SideCrossIterator::SideCrossIterator(const MagicalContainer& c) : container(c),
                                                        forwardIt(c.elements.begin()),
                                                        backwardIt(c.elements.end() - 1),
                                                        isForward(true) {}

SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container),
                                                            forwardIt(other.forwardIt),
                                                            backwardIt(other.backwardIt),
                                                            isForward(other.isForward) {}

SideCrossIterator::~SideCrossIterator() {}

SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        forwardIt = other.forwardIt;
        backwardIt = other.backwardIt;
        isForward = other.isForward;
    }
    return *this;
}

bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return forwardIt == other.forwardIt && backwardIt == other.backwardIt;
}

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool SideCrossIterator::operator>(const SideCrossIterator& other) const {
    if (isForward)
        return forwardIt > other.forwardIt;
    else
        return backwardIt > other.backwardIt;
}

bool SideCrossIterator::operator<(const SideCrossIterator& other) const {
    if (isForward)
        return forwardIt < other.forwardIt;
    else
        return backwardIt < other.backwardIt;
}

int SideCrossIterator::operator*() const {
    if (isForward)
        return *forwardIt;
    else
        return *backwardIt;
}

SideCrossIterator& SideCrossIterator::operator++() {
    if (isForward) {
        ++forwardIt;
        isForward = false;
    } else {
        --backwardIt;
        isForward = true;
    }
    return *this;
}

static SideCrossIterator begin(const MagicalContainer& container) {
    return SideCrossIterator(container);
}

static SideCrossIterator end(const MagicalContainer& container) {
    return SideCrossIterator(container, container.elements.end());
}
