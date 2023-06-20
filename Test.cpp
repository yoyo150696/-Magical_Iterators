#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;



TEST_CASE("Add and remove elemnts") {
    MagicalContainer container;
    for (int i = 0; i < 10; ++i) {
        CHECK(container.size() == i);
        container.addElement(i);
        CHECK(container.size() == i + 1);
    }
    CHECK_THROWS(container.addElement(5));
    CHECK_NOTHROW(container.removeElement(5));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_THROWS(container.removeElement(12));
}



TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(-10);
    container.addElement(-30);
    container.addElement(15);

    CHECK(container.size() == 5);

    MagicalContainer::AscendingIterator it(container);
    CHECK(*it == -30);
    ++it;
    CHECK(*it == -10);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 15);
    ++it;
    CHECK(*it == 20);
}

TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(19);
    container.addElement(-10);
    container.addElement(-5);
    container.addElement(3);
    container.addElement(15);
    CHECK(container.size() == 6);

    MagicalContainer::PrimeIterator it(container);
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
}

TEST_CASE("SideCrossIterator") {

    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(10);
    container.addElement(20);
    container.addElement(-10);
    container.addElement(-30);
    container.addElement(15);
    CHECK(container.size() == 5);

    MagicalContainer::SideCrossIterator it(container);
    CHECK(*it == -30);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(*it == -10);
    ++it;
    CHECK(*it == 15);
    ++it;
    CHECK(*it == 10);
}

TEST_CASE("Comparison between two different containers"){
    MagicalContainer one;
    MagicalContainer two;
    MagicalContainer three;
    one.addElement(1);
    one.addElement(2);
    two.addElement(1);
    two.addElement(3);
    three.addElement(1);
    three.addElement(2);

    SUBCASE("AscendingIterator")
   {
        MagicalContainer::AscendingIterator it1(one);
        ++it1;
        MagicalContainer::AscendingIterator it2(two);
        MagicalContainer::AscendingIterator it3(three);

        CHECK_THROWS(it1 = it2);
        CHECK_NOTHROW(it1 = it2);
   }
   SUBCASE("SideCrossIterator")
   {
        MagicalContainer::SideCrossIterator it1(one);
        ++it1;
        MagicalContainer::SideCrossIterator it2(two);
        MagicalContainer::SideCrossIterator it3(three);

        CHECK_THROWS(it1 = it2);
        CHECK_NOTHROW(it1 = it2);
   }
   SUBCASE("PrimeIterator")
   {
         MagicalContainer::PrimeIterator it1(one);
        ++it1;
        MagicalContainer::PrimeIterator it2(two);
        MagicalContainer::PrimeIterator it3(three);

        CHECK_THROWS(it1 = it2);
        CHECK_NOTHROW(it1 = it2);
   }
}

TEST_CASE("changing containers"){
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(-10);
    container.addElement(-30);
    container.addElement(15);

    MagicalContainer::AscendingIterator it(container);
    ++it;
    container.addElement(-5);
    CHECK(*it == -5);

}

TEST_CASE("index"){
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(-10);
    container.addElement(-30);
    container.addElement(15);

    MagicalContainer::AscendingIterator it1(container);
    ++it1;
    MagicalContainer::AscendingIterator it2(container);
    CHECK(it1 > it2);
    ++it2;
    ++it2;
    CHECK(it2 > it1);
}

