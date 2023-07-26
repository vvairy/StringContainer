#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <fstream>
#include <string>
class string_list
{
public:
    string_list(std::vector<std::string> input)
    {
        this->list = input;
        std::sort(this->list.begin(), this->list.end(), &string_list::comp);
        this->sz = input.size();
    }
    string_list()
    {
        this->sz = 0;
    }


    void insert(const std::string& inserting_str)
    {
        for (size_t i = 0; i < this->sz; ++i)
            if (inserting_str.compare(this->list[i]) < 0)
            {
                forwardShift(i);
                this->list[i] = inserting_str;
                ++this->sz;
                return;
            }
        this->list.push_back(inserting_str);
        ++this->sz;
    }

    void erase(size_t idx)
    {
        for (size_t i = idx; i < this->sz - 1; ++i)
            this->list[i] = this->list[i + 1];
        this->list.pop_back();
        --this->sz;
    }

    std::string operator[](size_t idx)
    {
        if (idx >= this->sz)
            throw std::exception("out of range");
        return this->list[idx];
    }
    size_t size()
    {
        return this->sz;
    }
private:
    static bool comp(const std::string& str1, const std::string& str2)
    {
        return str1.compare(str2) < 0;
    }

    void forwardShift(size_t idx)
    {
        this->list.push_back(this->list.back());
        for (size_t i = this->sz - 1; i != idx; --i)
            this->list[i] = this->list[i - 1];
    }

    std::vector<std::string> list;
    size_t sz;
};

int main()
{// Example usage of string_list 
    std::vector<std::string> input_strings = { "apple", "orange", "banana", "grape" };
    string_list myList(input_strings);

    myList.insert("kiwi");
    myList.erase(1);

    for (size_t i = 0; i < myList.size(); ++i)
    {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}