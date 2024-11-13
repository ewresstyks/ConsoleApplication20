#include<iostream>
#include<time.h>
using namespace std;

template<class T >
class MyArray
{
    T* mas = nullptr;
    int size;
public:
    MyArray();
    void Output();
    ~MyArray();
    T operator[](int index);
    int GetSize()const
    {
        return size;
    }
    T* GetPtr()const
    {
        return mas;
    }
    void SetSize(int s)
    {
        size = s;
    }
    void SetPtr(T* ptr)
    {
        mas = ptr;
    }
};
template<class T>MyArray<T>::MyArray()
{
    size = 10;
    mas = new T[10];
    for (int i = 0; i < size; i++)
    {
        mas[i] = rand() % 100 * 1.2;
    }
}
template<class T>void MyArray<T>::Output()
{
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << "\t";
    }
    cout << endl << endl;
}
template<class T>MyArray<T>::~MyArray()
{
    if (mas != nullptr)
    {
        delete[] mas;
    }
}
template<class T>T MyArray<T>::operator[](int index)
{
    return mas[index];
}


//Реализовать собственный класс Point(с перегрузками), и использовать в шаблоне класса.
//
class Point
{
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    int GetX();
    int GetY();
    Point& operator=(double obj);
};


Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::GetX()
{
    return x;
}

int Point::GetY()
{
    return y;
}

Point& Point::operator=(double obj)
{
    this->x = obj;
    this->y = obj;
    return *this;
}

ostream& operator<< (ostream& os, Point& obj)
{
    os << "(" << obj.GetX() << ", " << obj.GetY() << ")";
    return os;
}

void main()
{
    srand(time(0));
    /*MyArray<int> obj1;
    obj1.Output();

    MyArray<char> obj2;
    obj2.Output();

    MyArray<double>obj3;
    obj3.Output();*/

    MyArray<Point> obj4;
    obj4.Output();
    system("pause");
}