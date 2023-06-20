#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

namespace ariel{
    class MagicalContainer {

        class Node{
            public:
                int data;
                Node *next;
                Node *bef;
        };
        private:
            
            Node *head;
            Node *headpr;
            Node *headcr;
            int node_index;
            int _size;
            int pr_size;  
            int as_index = 1;
            int pr_index = 1;
            int cr_index = 1;      
        public:
            MagicalContainer();

            bool operator==(const MagicalContainer& other) const;

            bool operator!=(const MagicalContainer& other) const;

            void updateHead(int element, Node*& headPtr, int& size);

            void removeHead(int element, Node*& headPtr, int& size);

            void freeLinkedList();

            void update_cr();

            void addElement(int element);

            void removeUpdate(int element, Node*& headPtr, int& size);

            void removeElement(int element);

            int size() const;

            int get_data(int num);

            static bool isprime(int num);

        class AscendingIterator {
            private:
                Node *curr;
                MagicalContainer& container;
                int index = 1;
                bool first = true;
                AscendingIterator(MagicalContainer& cont,int index);

            public:
                AscendingIterator(MagicalContainer& cont);

                AscendingIterator(const AscendingIterator& other);


                ~AscendingIterator();

                AscendingIterator operator=(const AscendingIterator& other);

                bool operator==(const AscendingIterator& other) const;

                bool operator!=(const AscendingIterator& other) const;

                bool operator>(const AscendingIterator& other) const;

                bool operator<(const AscendingIterator& other) const;

                int operator*() const;

                AscendingIterator operator++() ;

                MagicalContainer::AscendingIterator begin();

                AscendingIterator end();

        };
        class PrimeIterator {
            private:
                MagicalContainer& container;
                Node *curr;
                bool first = true;
                int index = 1;
                PrimeIterator(MagicalContainer& container , int index);

            public:
                PrimeIterator(MagicalContainer& container);

                PrimeIterator(const PrimeIterator& other);

                ~PrimeIterator();

                PrimeIterator operator=(const PrimeIterator& other) ;

                bool operator==(const PrimeIterator& other) const;

                bool operator!=(const PrimeIterator& other) const;

                bool operator>(const PrimeIterator& other) const;

                bool operator<(const PrimeIterator& other) const;

                int operator*() const;

                PrimeIterator operator++() ;

                PrimeIterator begin() ;

                PrimeIterator end() ;

        };
        class SideCrossIterator {
        private:
            MagicalContainer& container;
        
            Node *curr;
            bool first = true;
            int index = 1;
            SideCrossIterator(MagicalContainer& container,int index);

        public:
            SideCrossIterator( MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other);

            ~SideCrossIterator();

            SideCrossIterator operator=(const SideCrossIterator& other);

            bool operator==(const SideCrossIterator& other) const ;
            bool operator!=(const SideCrossIterator& other) const ;

            bool operator>(const SideCrossIterator& other) const ;

            bool operator<(const SideCrossIterator& other) const ;

            int operator*() const;

            SideCrossIterator operator++();

            SideCrossIterator begin();

            SideCrossIterator end();
            };

    };
}
