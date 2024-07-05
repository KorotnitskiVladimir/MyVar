//
//  MyVar.hpp
//  MyVar
//
//  Created by Коротницкий Владимир on 12.06.2024.
//

#ifndef MyVar_hpp
#define MyVar_hpp
#include <iostream>
using namespace std;

class MyVar
{
private:
    int* i;
    double* d;
    string str;
public:
    MyVar(): i{nullptr}, d{nullptr}, str{""} {}
    MyVar(int x);
    MyVar(double y);
    MyVar(const char* s);
    MyVar(const MyVar &obj);
    ~MyVar();
    int getInt() const;
    double getDouble() const;
    string getString() const;
    void print() const;
    void setInt(int x);
    void setDouble(double y);
    void setString(const char* s);
    MyVar operator=(const MyVar &obj);
    MyVar operator+(const MyVar &obj);
    MyVar operator-(const MyVar &obj);
    MyVar operator*(const MyVar &obj);
    MyVar operator/(const MyVar &obj);
    MyVar& operator+=(const MyVar &obj);
    MyVar& operator-=(const MyVar &obj);
    MyVar& operator*=(const MyVar &obj);
    MyVar& operator/=(const MyVar &obj);
    bool operator<(const MyVar &obj);
    bool operator>(const MyVar &obj);
    bool operator<=(const MyVar &obj);
    bool operator>=(const MyVar &obj);
    bool operator==(const MyVar &obj);
    bool operator!=(const MyVar &obj);
};


#endif /* MyVar_hpp */
