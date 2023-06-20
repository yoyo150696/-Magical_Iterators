#include <MagicalContainer.hpp>

using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer():_size(0) , pr_size(0),head(nullptr),headpr(nullptr),
headcr(nullptr), node_index(0){}

bool MagicalContainer::operator==(const MagicalContainer& other) const{
    Node *curr = head;
    Node *ocurr = other.head;
    while(curr!=nullptr&&ocurr!=nullptr){
        if(curr->data != ocurr->data)
            return false;
        curr = curr->next;
        ocurr = ocurr->next;
    }
    if((curr!=nullptr&&ocurr==nullptr)||(curr==nullptr&&ocurr!=nullptr))
        return false;
    return true;
}

bool MagicalContainer::operator!=(const MagicalContainer& other) const{
    return !(*this == other);
}

void MagicalContainer::freeLinkedList() {
    while (headcr != nullptr) {
        Node* temp = headcr;
        headcr = headcr->next;
        free(temp);
    }
    
}

void MagicalContainer::updateHead(int element, Node*& headPtr, int& size) {
    size++;
    if (headPtr == nullptr) {
        headPtr = new Node();
        headPtr->data = element;
        headPtr->next = nullptr;
    } else {
        if (element < headPtr->data) {
            Node* temp = headPtr;
            headPtr = new Node;
            headPtr->data = element;
            headPtr->next = temp;
            return;
        }
        Node* curr = headPtr;
        while (curr->next) {
            if (curr->next->data == element) {
                size--;
                return;
            }
            if (curr->next->data > element) {
                Node* temp = curr->next;
                curr->next = new Node;
                curr->next->data = element;
                curr->next->next = temp;
                return;
            }
            curr = curr->next;
        }
        curr->next = new Node;
        curr->next->data = element;
        curr->next->next = nullptr;
    }
}

void MagicalContainer::update_cr(){
    freeLinkedList();
    node_index = 1;
    headcr = new Node;
    headcr->data  = get_data(0);
    headcr->next = nullptr;
    Node *crCurr = headcr;
    for(int i=1;i<_size;i++){
        crCurr->next = new Node;
        if(i%2==0){
            crCurr->next->data = get_data(node_index);
            node_index++;
        }
        else
            crCurr->next->data = get_data(_size - node_index);
        crCurr->next->next = nullptr;    
        crCurr = crCurr->next;          
    }
    
}

void MagicalContainer::addElement(int element){
    updateHead(element,head,_size);
    if(isprime(element))
        updateHead(element,headpr,pr_size);
    update_cr();    
   
}

void MagicalContainer::removeUpdate(int element, Node*& headPtr, int& size) {
    if (headPtr == nullptr)
        throw std::runtime_error("error");
    else {
        size--;
        if (headPtr->data == element) {
            Node* temp = headPtr;
            headPtr = headPtr->next;
            delete temp;
        } else {
            Node* curr = headPtr;
            while (curr->next != nullptr) {
                Node* next = curr->next;
                if (next->data == element) {
                    if (next->next == nullptr) {
                        delete next;
                        curr->next = nullptr;
                        return;
                    } else {
                        next->next->bef = curr;
                        curr->next = next->next;
                        delete next;
                        return;
                    }
                }
                curr = curr->next;
            }
            size++;
            throw std::runtime_error("error");
        }
    }
}


void MagicalContainer::removeElement(int element){
    removeUpdate(element,head,_size);
    if(isprime(element))
        removeUpdate(element,headpr,pr_size);
    update_cr();    
}

int MagicalContainer::size() const{
    return _size;
}

int MagicalContainer::get_data(int num){
    Node *curr;
    if(head != nullptr){
        curr = head;
        for(int i = 0;i < num;i++){
            curr = curr->next;
        }
    }
    return curr->data;
}

bool MagicalContainer::isprime(int number){
    if (number <= 1) {
        return false;
    }

    int sqrtNumber = sqrt(number);
    for (int divisor = 2; divisor <= sqrtNumber; ++divisor) {
        if (number % divisor == 0) {
            return false;
        }
    }

    return true;
}


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont,int ind):container(cont),index(ind) {
     if(ind == 1){
        first = true;
        if(container.head!=nullptr)
            curr = container.head;
        }

}


MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer& cont):container(cont) {
    if(first == true)
        if(container.head!=nullptr)
            curr = container.head;
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other):
container(other.container), index(other.index), curr(other.curr), first(other.first){}

MagicalContainer::AscendingIterator::~AscendingIterator(){}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
    if(container != other.container)
        throw runtime_error("error");
    return AscendingIterator{other.container};
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
    return container.as_index == other.container.as_index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    return index != other.index;
    
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
    return index > other.index;}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
    return index < other.index;}

int MagicalContainer::AscendingIterator::operator*() const{
    return curr->data;
    }

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(){
    if(index >= container.size()+1)
        throw runtime_error("error");
    if(first)
        first = false;
    index++;
    container.as_index++;
    curr = curr->next;
    return AscendingIterator{container};
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){ 
    return AscendingIterator{container,1};
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
    return AscendingIterator{container,container.size()+1};
}


MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont, int ind)
    : container(cont), index(ind) {
        if(ind == 1){
            first = true;
            if(container.headpr!=nullptr)
                curr = container.headpr;
        }
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont): container(cont) {
    if(first == true)
        if(container.headpr!=nullptr)
            curr = container.headpr;
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    :container(other.container), index(other.index), curr(other.curr), first(other.first) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if(container != other.container)
        throw runtime_error("error");
    return PrimeIterator{other.container};
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return index != other.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return index > other.index;;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return index < other.index;;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return curr->data;}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++() {
    if(index >= container.pr_size+1)
        throw runtime_error("error");
    if(first)
        first = false;
    index++;
    curr = curr->next;
    return PrimeIterator{container};
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator{container, 1};
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return PrimeIterator{container,container.pr_size+1};
}

MagicalContainer::SideCrossIterator::SideCrossIterator( MagicalContainer& cont,int ind): container(cont), index(ind){
    if(ind == 1){
        first = true;
        if(container.headcr!=nullptr)
            curr = container.headcr;
    }

}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont):container(cont){
    if(first == true)
        if(container.headcr!=nullptr)
            curr = container.headcr;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other):container(other.container),index(other.index){}

MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
    if(container != other.container)
        throw runtime_error("error");
    return SideCrossIterator{other.container};
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
    return index == other.index;}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
    return index != other.index;}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
    return index > other.index;}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
    return index < other.index;}

int MagicalContainer::SideCrossIterator::operator*() const{
    return curr->data; 
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(){
    if(index >= container.size()+1)
        throw runtime_error("error");
    if(first)
        first = false;
    index++;
    curr = curr->next;
    return SideCrossIterator{container};
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
    return SideCrossIterator{container,1};
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
    return SideCrossIterator{container,container.size()+1};
}

