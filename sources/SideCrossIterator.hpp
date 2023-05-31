#pragma once
#include <MagicalContainer.hpp>

class SideCrossIterator {
    private:
        const MagicalContainer& container;
        std::vector<int>::const_iterator forwardIt;
        std::vector<int>::const_iterator backwardIt;
        bool isForward;

    public:
        SideCrossIterator(const MagicalContainer& c) : container(c),
                                                        forwardIt(c.elements.begin()),
                                                        backwardIt(c.elements.end() - 1),
                                                        isForward(true) {}

        SideCrossIterator(const SideCrossIterator& other) : container(other.container),
                                                            forwardIt(other.forwardIt),
                                                            backwardIt(other.backwardIt),
                                                            isForward(other.isForward) {}

        ~SideCrossIterator() {}

        SideCrossIterator& operator=(const SideCrossIterator& other) {
            if (this != &other) {
                forwardIt = other.forwardIt;
                backwardIt = other.backwardIt;
                isForward = other.isForward;
            }
            return *this;
        }

        bool operator==(const SideCrossIterator& other) const {
            return forwardIt == other.forwardIt && backwardIt == other.backwardIt;
        }

        bool operator!=(const SideCrossIterator& other) const {
            return !(*this == other);
        }

        bool operator>(const SideCrossIterator& other) const {
            if (isForward)
                return forwardIt > other.forwardIt;
            else
                return backwardIt > other.backwardIt;
        }

        bool operator<(const SideCrossIterator& other) const {
            if (isForward)
                return forwardIt < other.forwardIt;
            else
                return backwardIt < other.backwardIt;
        }

        int operator*() const {
            if (isForward)
                return *forwardIt;
            else
                return *backwardIt;
        }

        SideCrossIterator& operator++();

        static SideCrossIterator begin(const MagicalContainer& container);

        static SideCrossIterator end(const MagicalContainer& container);
    };