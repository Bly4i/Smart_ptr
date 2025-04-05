//Задание 1
#include <iostream>
#include <Windows.h>
#include<memory>
#include<vector>

using namespace std;

class tridiagonal_matrix
{
public:
    vector<double> m_down;
    vector<double> m_upper;
    vector<double> m_middle;

    tridiagonal_matrix(
        const vector<double>& down,
        const vector<double>& upper,
        const vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {
    }

    ~tridiagonal_matrix()
    {
        cout << "destructor called\n";
    }

    unique_ptr<tridiagonal_matrix> clone() const
    {
        return make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
    }
};




int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto down = vector<double>{ -4.0, 5.0 };
    auto upper = vector<double>{ 14.0, 8.0 };
    auto middle = vector<double>{ 3.0, 1.0, 7.0 };

    auto matrix = make_unique<tridiagonal_matrix>(down, upper, middle);

    auto matrix_clone = matrix->clone();

    cout << "Изначальная матрица:\n";
    cout << "Down: ";
    for (double val : matrix->m_down) cout << val << " ";
    cout << "\nUpper: ";
    for (double val : matrix->m_upper) cout << val << " ";
    cout << "\nMiddle: ";
    for (double val : matrix->m_middle) cout << val << " ";
    cout << "\n\n";

    cout << "Копия матрицы:\n";
    cout << "Down: ";
    for (double val : matrix_clone->m_down) cout << val << " ";
    cout << "\nUpper: ";
    for (double val : matrix_clone->m_upper) cout << val << " ";
    cout << "\nMiddle: ";
    for (double val : matrix_clone->m_middle) cout << val << " ";
    cout << "\n";

    return 0;
}

//Задание 2

#include <iostream>
#include <vector>
#include <memory>
#include <Windows.h>

using namespace std;


class node
{
public:
    int m_value;
    weak_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { cout << "destructor called\n"; }
};

int main2()
{
    {
        auto node1 = make_shared<node>(1);
        auto node2 = make_shared<node>(2);
        node1->parent = node2;
        node2->parent = node1;
    }

    return 0;
}

