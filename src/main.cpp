#include <iostream>
#include <vector>

using namespace std;

class MultiplyAlgorithm
{
public:
    vector<unsigned long long> liste;

private:
    // alanlar-fields
    int *row;
    // variables for combination operation
    unsigned long long n1;
    unsigned long long nr;
    unsigned long long r1;
    unsigned long long sonuc;

    // metotlar
    unsigned long long faktoriyel(int a)
    {
        unsigned long long f = 1;

        for (unsigned long long i = 1; i <= a; i++)
        {
            f *= i;
        }
        return f;
    }

    // combination formule
    void calculate(int *n)
    {
        for (int r = 0; r <= *n; r++)

        {
            n1 = faktoriyel(*n);
            nr = faktoriyel(*n - r);
            r1 = faktoriyel(r);

            sonuc = n1 / (nr * r1);
            liste.push_back(sonuc);
        }
    }

    // method that calculates 20th row for Addition Algorithm.
    void calculate20th()
    {
        for (int r = 0; r <= 20; r++)

        {
            n1 = faktoriyel(20);
            nr = faktoriyel(20 - r);
            r1 = faktoriyel(r);

            sonuc = n1 / (nr * r1);
            liste.push_back(sonuc);
        }
    }
    // writes results
    void writer()
    {

        for (unsigned long long i = 0; i <= *row; i++)
        {
            cout << liste.at(i) << "-";
        }

        cout << endl;
    }

public:
    // constructor
    MultiplyAlgorithm(int *n)
    {
        row = n;
        calculate(n);
        writer();
    }

    MultiplyAlgorithm()
    {
        calculate20th();
    }

    ~MultiplyAlgorithm()
    {
        delete this;
    }
};
//************************************************************************************//
class AdditionAlgorithm
{
private:
    // fields
    vector<unsigned long long> *vector1;
    vector<unsigned long long> *vector2;
    MultiplyAlgorithm *m;

private:
    // swap vector1 with vector2
    void vectorSwap()
    {
        vector1->swap(*vector2);
        vector2->clear();
    }

    // Writer writes last calculated values of vector1 that contains aimed row numbers.
    void writer()
    {
        for (int i = 0; i < vector1->size(); i++)
        {
            cout << vector1->at(i) << "-";
        }
        cout << endl;
    }

    // numGenerator generates new numbers from vector1 for vector2.
    // it basiclly add vector1's consecutive elements to each other.
    unsigned long long numGenerator(vector<unsigned long long> *v1, int *step)
    {
        unsigned long long generetedNum;
        // vectors starts with 0 to count.
        generetedNum = v1->at(*step) + v1->at(*step + 1);
        return generetedNum;
    }

    // Creates new vector-row's numbers according to vector1's values.
    void vectorCreate()
    {
        // first element of vector 2
        vector2->push_back(1);

        for (int i = 0; i <= vector1->size() - 2; i++)
        {
            vector2->push_back(numGenerator(vector1, &i));
        }
        vector2->push_back(1);
    }

public:
    AdditionAlgorithm(int *rowNum)
    {
        vector1 = new vector<unsigned long long>;
        vector2 = new vector<unsigned long long>;
        // 20th row's numbers calculated when Multiply Alghorithym newed.
        m = new MultiplyAlgorithm();
        vector1 = &m->liste;

        for (long i = 20; i < *rowNum; i++)
        {
            vectorCreate();
            vectorSwap();
        }

        writer();
        cout << endl;
    }

    // Destructor
    ~AdditionAlgorithm()
    {
        delete m;
        delete this;
    }
};

int main()
{
    // line number
    int inputNumber;

    cout << "Enter the line number you want calculated:";
    cin >> inputNumber;
    cout << endl;

    if (inputNumber > 20)
        AdditionAlgorithm *al = new AdditionAlgorithm(&inputNumber);
    else
        MultiplyAlgorithm *al = new MultiplyAlgorithm(&inputNumber);

    system("pause");
    return 0;
}

/*
I calculated 20.000 row!
I haven't discovered the limits yet.
*/