//
//  MyVar.cpp
//  MyVar
//
//  Created by Коротницкий Владимир on 12.06.2024.
//

#include "MyVar.hpp"
#include <iostream>
using namespace std;

MyVar::MyVar(int x)
{
    i = new int{x};
    d = nullptr;
    str = "";
}

MyVar::MyVar(double y)
{
    i = nullptr;
    d = new double{y};
    str = "";
}

MyVar::MyVar(const char* s)
{
    i = nullptr;
    d = nullptr;
    str = s;
}

MyVar::~MyVar()
{
    if (i)
        delete i;
    if (d)
        delete d;
}

int MyVar::getInt() const
{
    return *i;
}

double MyVar::getDouble() const
{
    return *d;
}

string MyVar::getString() const
{
    return str;
}

void MyVar::print() const
{
    if (i)
        cout << *i << endl;
    if (d)
        cout << *d << endl;
    if (str!="")
        cout << str << endl;
}

void MyVar::setInt(int x)
{
    if (!d && str=="")
    {
        if (i)
            delete i;
        i = new int{x};
    }
    if(d)
    {
        delete d;
        i = new int(x);
    }
    if (str!="")
    {
        str="";
        i = new int(x);
    }
}

void MyVar::setDouble(double y)
{
    if (!i && str=="")
    {
        if (d)
            delete d;
        d = new double{y};
    }
    if (i)
    {
        delete i;
        d = new double(y);
    }
    if (str!="")
    {
        str="";
        d = new double(y);
    }
}

void MyVar::setString(const char* s)
{
    if (!i && !d)
    {
        str = s;
    }
    if (i)
    {
        delete i;
        str = s;
    }
    if (d)
    {
        delete d;
        str = s;
    }
}

MyVar::MyVar(const MyVar &obj)
{
    if (obj.i)
    {
        this->i = new int(*(obj.i));
        this->d = nullptr;
        this->str = "";
    }
    if (obj.d)
    {
        this->d = new double(*(obj.d));
        this->i = nullptr;
        this->str = "";
    }
    if (obj.str!="")
    {
        this->str = obj.str;
        this->i = nullptr;
        this->d = nullptr;
    }
}

MyVar MyVar::operator=(const MyVar &obj)
{
    if (obj.i)
    {
        if (this->i)
            delete this->i;
        this->i = new int(*(obj.i));
        this->d = nullptr;
        this->str = "";
    }
    if (obj.d)
    {
        if (this->d)
            delete this->d;
        this->d = new double(*(obj.d));
        this->i = nullptr;
        this->str = "";
    }
    if (obj.str!="")
    {
        this->i = nullptr;
        this->d = nullptr;
        this->str = obj.str;
    }
    
    return *this;
}

MyVar MyVar::operator+(const MyVar &obj)
{
    MyVar t;
    if (this->i)
    {
        t.i = new int(*(this->i));
        t.d = nullptr;
        t.str = "";
        if (obj.i)
            *(t.i)+=(*(obj.i));
        if (obj.d)
            *(t.i)+=(int)(*(obj.d));
        if (obj.str!="")
            *(t.i)+=stoi(obj.str);
    }
    if (this->d)
    {
        t.i = nullptr;
        t.d = new double(*(this->d));
        t.str = "";
        if (obj.i)
            *(t.d)+=*(obj.i);
        if (obj.d)
            *(t.d)+=*(obj.d);
        if (obj.str!="")
            *(t.d)+=stod(obj.str);
    }
    if (this->str!="")
    {
        t.i = nullptr;
        t.d = nullptr;
        t.str = this->str;
        if (obj.i)
            t.str+= to_string(*(obj.i));
        if (obj.d)
            t.str+= to_string(*(obj.d));
        if (obj.str!="")
            t.str+=obj.str;
    }
    
    return t;
}

MyVar MyVar::operator-(const MyVar &obj)
{
    MyVar t;
    if (this->i)
    {
        t.i = new int(*(this->i));
        t.d = nullptr;
        t.str = "";
        if (obj.i)
            *(t.i)-=(*(obj.i));
        if (obj.d)
            *(t.i)-=(int)(*(obj.d));
        if (obj.str!="")
            *(t.i)-=stoi(obj.str);
    }
    if (this->d)
    {
        t.i = nullptr;
        t.d = new double(*(this->d));
        t.str = "";
        if (obj.i)
            *(t.d)+=*(obj.i);
        if (obj.d)
            *(t.d)+=*(obj.d);
        if (obj.str!="")
            *(t.d)-=stod(obj.str);
    }
    if (this->str!="")
    {
        t.i = nullptr;
        t.d = nullptr;
        t.str = this->str;
    }
    
    return t;
}

MyVar MyVar::operator*(const MyVar &obj)
{
    MyVar t;
    if (this->i)
    {
        t.i = new int(*(this->i));
        t.d = nullptr;
        t.str = "";
        if (obj.i)
            *(t.i)*=(*(obj.i));
        if (obj.d)
            *(t.i)*=(int)(*(obj.d));
        if (obj.str!="")
            *(t.i)*=stoi(obj.str);
    }
    if (this->d)
    {
        t.i = nullptr;
        t.d = new double(*(this->d));
        t.str = "";
        if (obj.i)
            *(t.d)*=*(obj.i);
        if (obj.d)
            *(t.d)*=*(obj.d);
        if (obj.str!="")
            *(t.d)*=stod(obj.str);
    }
    if (this->str!="")
    {
        t.i = nullptr;
        t.d = nullptr;
        t.str = "";
        if (obj.str!="")
        {
            for (int j=0; j<this->str.length(); j++)
                for (int k=0; k<obj.str.length(); k++)
                    if (this->str[j] == obj.str[k])
                    {
                        t.str+=this->str[j];
                        break;
                    }
        }
    }
    
    return t;
}

MyVar MyVar::operator/(const MyVar &obj)
{
    MyVar t;
    if (this->i)
    {
        t.i = new int(*(this->i));
        t.d = nullptr;
        t.str = "";
        if (obj.i)
            *(t.i)/=(*(obj.i));
        if (obj.d)
            *(t.i)/=(int)(*(obj.d));
        if (obj.str!="")
            *(t.i)/=stoi(obj.str);
    }
    if (this->d)
    {
        t.i = nullptr;
        t.d = new double(*(this->d));
        t.str = "";
        if (obj.i)
            *(t.d)/=*(obj.i);
        if (obj.d)
            *(t.d)/=*(obj.d);
        if (obj.str!="")
            *(t.d)/=stod(obj.str);
    }
    if (this->str!="")
    {
        t.i = nullptr;
        t.d = nullptr;
        t.str = "";
        if (obj.str!="")
        {
            for (int i=0; i<this->str.length(); i++)
            {
                int c = 0;
                for (int j=0; j<obj.str.length(); j++)
                    if (this->str[i] != obj.str[j])
                        c++;
                if (c == obj.str.length())
                    t.str+=this->str[i];
            }
        }
    }
    
    return t;
}

MyVar& MyVar::operator+=(const MyVar &obj)
{
    *this = *this + obj;
    
    return *this;
}

MyVar& MyVar::operator-=(const MyVar &obj)
{
    *this = *this - obj;
    
    return *this;
}

MyVar& MyVar::operator*=(const MyVar &obj)
{
    *this = *this * obj;
    
    return *this;
}
MyVar& MyVar::operator/=(const MyVar &obj)
{
    *this = *this / obj;
    
    return *this;
}

bool MyVar::operator<(const MyVar &obj)
{
    if (this->i)
    {
        if (obj.i)
            if (*(this->i) < *(obj.i))
                return true;
        if (obj.d)
            if (*(this->i) < *(obj.d))
                return true;
        if (obj.str!="")
            if (*(this->i) < stoi(obj.str))
                return true;
    }
    if (this->d)
    {
        if (obj.i)
            if (*(this->d) < *(obj.i))
                return true;
        if (obj.d)
            if (*(this->d) < *(obj.d))
                return true;
        if (obj.str!="")
            if (*(this->d) < stod(obj.str))
                return true;
    }
    if (this->str!="")
    {
        if (obj.i)
            if (stoi(this->str) < *(obj.i))
                return true;
        if (obj.d)
            if (stod(this->str) < *(obj.d))
                return true;
        if (obj.str!="")
            if (this->str < obj.str)
                return true;
    }
    
    return false;
}

bool MyVar::operator>(const MyVar &obj)
{
    if (this->i)
    {
        if (obj.i)
            if (*(this->i) > *(obj.i))
                return true;
        if (obj.d)
            if (*(this->i) > *(obj.d))
                return true;
        if (obj.str!="")
            if (*(this->i) > stoi(obj.str))
                return true;
    }
    if (this->d)
    {
        if (obj.i)
            if (*(this->d) > *(obj.i))
                return true;
        if (obj.d)
            if (*(this->d) > *(obj.d))
                return true;
        if (obj.str!="")
            if (*(this->d) > stod(obj.str))
                return true;
    }
    if (this->str!="")
    {
        if (obj.i)
            if (stoi(this->str) > *(obj.i))
                return true;
        if (obj.d)
            if (stod(this->str) > *(obj.d))
                return true;
        if (obj.str!="")
            if (this->str > obj.str)
                return true;
    }
    
    return false;
}

bool MyVar::operator==(const MyVar &obj)
{
    if (this->i)
    {
        if (obj.i)
            if (*(this->i) == *(obj.i))
                return true;
        if (obj.d)
            if (*(this->i) == *(obj.d))
                return true;
        if (obj.str!="")
            if (*(this->i) == stoi(obj.str))
                return true;
    }
    if (this->d)
    {
        if (obj.i)
            if (*(this->d) == *(obj.i))
                return true;
        if (obj.d)
            if (*(this->d) == *(obj.d))
                return true;
        if (obj.str!="")
            if (*(this->d) == stod(obj.str))
                return true;
    }
    if (this->str!="")
    {
        if (obj.i)
            if (stoi(this->str) == *(obj.i))
                return true;
        if (obj.d)
            if (stod(this->str) == *(obj.d))
                return true;
        if (obj.str!="")
            if (this->str == obj.str)
                return true;
    }
    
    return false;
}

bool MyVar::operator<=(const MyVar &obj)
{
    if (*this < obj || *this == obj)
        return true;
    else
        return false;
}

bool MyVar::operator>=(const MyVar &obj)
{
    if (*this > obj || *this == obj)
        return true;
    else
        return false;
}

bool MyVar::operator!=(const MyVar &obj)
{
    if ( (*this == obj) == false)
        return true;
    else
        return false;
}
