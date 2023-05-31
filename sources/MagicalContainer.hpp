#include <iostream>
#include <vector>
#include <cmath>

class MagicalContainer {
private:
    std::vector<int> elements;

public:
    void addElement(int element);

    void removeElement(int element);

    int getSize() const;
};