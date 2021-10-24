#include <iostream>
#include <iterator>
#include <vector>
/* Print all digits in the given number */


void digits(int n) {
    std::vector<int> res;
    while (n !=0) {
        res.push_back(n%10);
        n/=10;
    }
    for (auto it = res.crbegin(); it!=res.crend(); ++it) {
        std::cout << *it <<", ";
    }
}
// Complexity O(lgN) in time and O(lgN) in space;
int main() {

    digits(47402340);
    return 0;
}