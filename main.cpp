//
//  main.cpp
//  MyVar
//
//  Created by Коротницкий Владимир on 12.06.2024.
//

#include <iostream>
#include "MyVar.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    MyVar v1("21");
    MyVar v2(21);
    cout << (v2 != v1) << endl;
    
    return 0;
}
