#pragma once
#include <MagicalContainer.hpp>

class PrimeIterator {
    private:
        const MagicalContainer& container;
        std::vector<int>::const_iterator it;

    public:
        PrimeIterator(const MagicalContainer& c);

        PrimeIterator(const PrimeIterator& other) : container(other.container), it(other.it) {}

        ~PrimeIterator() {}

        PrimeIterator& operator=(const PrimeIterator& other) ;
        bool operator==(const PrimeIterator& other) const;

        bool operator!=(const PrimeIterator& other) const;

        bool operator>(const PrimeIterator& other) const;

        bool operator<(const PrimeIterator& other) const;

        int operator*() const;

        PrimeIterator& operator++() ;

        static PrimeIterator begin(const MagicalContainer& container) ;

        static PrimeIterator end(const MagicalContainer& container) ;

    private:
        void findNextPrime() ;

        bool isPrime(int num) const;
};