#include <iostream>
#include <vector>
#include <iomanip>

using std::cout; using std::vector;
using std::endl; using std::setw;

constexpr int VECTOR_X = 4;
constexpr int VECTOR_Y = 6;

int main()
{
    vector<vector<int> > vector_2d(VECTOR_X, vector<int> (VECTOR_Y, 0));

    std::srand(std::time(nullptr));
    for (auto &item : vector_2d) {
        for (auto &i : item) {
            i = rand() % 100;
            cout << setw(2) << i << "; ";
        }
        cout << endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}
