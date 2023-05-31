#pragma once
#include <MagicalContainer.hpp>

class AscendingIterator {
    private:
        const MagicalContainer& container;
        std::vector<int>::const_iterator it;

    public:
        AscendingIterator(const MagicalContainer& c);

        AscendingIterator(const AscendingIterator& other);

        ~AscendingIterator();

        AscendingIterator& operator=(const AscendingIterator& other);

        bool operator==(const AscendingIterator& other) const;

        bool operator!=(const AscendingIterator& other) const;

        bool operator>(const AscendingIterator& other) const;

        bool operator<(const AscendingIterator& other) const;

        int operator*() const;

        AscendingIterator& operator++() ;

        static AscendingIterator begin(const MagicalContainer& container);

        static AscendingIterator end(const MagicalContainer& container);
    };