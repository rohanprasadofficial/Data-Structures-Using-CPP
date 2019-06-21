#include <vector>

using namespace std;

int main()
{

    //vector<datatype> vector_name;

    vector<int> v;

    v.push_back(1); // 1
    v.push_back(2); // 1 2
    v.push_back(3); // 1 2 3

    v.pop_back(); //  1  2
    v.pop_back(); //1
    return 0;
}
