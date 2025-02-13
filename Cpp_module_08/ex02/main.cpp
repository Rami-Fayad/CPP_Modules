#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterating through MutantStack
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Stack contents using iterators:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

     std::list<int> lst;
lst.push_back(5);
lst.push_back(17);
lst.pop_back();
lst.push_back(3);
lst.push_back(5);
lst.push_back(737);
lst.push_back(0);

std::cout << "List contents using iterators:" << std::endl;
for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << std::endl;
}

    std::stack<int> s(mstack);  // Copying to standard stack
    return 0;
}
