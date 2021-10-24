#include <iostream>
#include <stack>
template<typename T>
void print(const std::stack<T>& original, const char* s = "")
{ // copy st
    std::stack<T> st(original);
    std::cout << s << ": | ";
    while (!st.empty())
    {
        std::cout << st.top() << " | ";
        st.pop();
    }
    std::cout << "\n";
}

template<typename T>
void sortStack(std::stack<T>& initial)
{
    std::stack<T> tmpStack;
    while (!initial.empty())
    {
        T temp = initial.top();
        initial.pop();

        while (!tmpStack.empty() && tmpStack.top() > temp)
        {
            T elem = tmpStack.top();
            tmpStack.pop();
            initial.push(elem);
            //   print(initial, "Initial");
            //  print(tmpStack, "tmpSrack");
        }

        tmpStack.push(temp);
    }
    while (!tmpStack.empty())
    {
        initial.push(tmpStack.top());
        tmpStack.pop();
    }
}

int main()
{
    std::stack<int> a;
    for (int v : { 34, 12, 68, 33, 14, 67, 9, 56 })
    {
        a.push(v);
    }
    print(a, "Before");
    sortStack(a);
    print(a, "After");

    return 0;
}