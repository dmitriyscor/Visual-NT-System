#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

// Base class for demonstration
class NoteBase 
{
    public:
        virtual void print() const = 0;
        virtual ~NoteBase() {}
};

class TextNote : public NoteBase 
{
        std::string text;
    public:
        TextNote(const std::string& t) : text(t) {}

        void print() const override 
        { 
            std::cout << "Text: " << text << std::endl; 
        }
};

class NumberNote : public NoteBase
{
        int number;
    public:
        NumberNote(int n) : number(n) {}
        void print() const override 
        { 
            std::cout << "Number: " << number << std::endl; 
        }
};

// Template for searching
template <typename T>
int linearSearch(const std::vector<T>& vec, const T& value) 
{
    for (size_t i = 0; i < vec.size(); ++i)
        if (vec[i] == value)
            return (int) i;

    return -1;
}

// Recursion example: factorial
int factorial(int n) 
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Usage (in main or elsewhere)
void demo() 
{
    std::vector<NoteBase*> notes;
    notes.push_back(new TextNote("hello"));
    notes.push_back(new NumberNote(42));
    for (auto n : notes) n->print();
    // cleanup
    for (auto n : notes) delete n;

    std::vector<int> nums = { 3, 1, 4, 1, 5 };
    int idx = linearSearch(nums, 4);
    std::cout << "Found 4 at: " << idx << std::endl;

    std::cout << "Factorial(5) = " << factorial(5) << std::endl;
}