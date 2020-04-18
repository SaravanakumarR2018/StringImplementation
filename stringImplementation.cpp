//
//  main.cpp
//  MyString
//
//  Created by SarvanaKumar on 11/03/20.
//  Copyright © 2020 SarvanaKumar. All rights reserved.
//

#include <iostream>
using namespace std;

class MyString
{
    char *stringptr;
    int size;
public:
    MyString(string str)
    {
        cout << "MyString String constructor for string" << str << endl;
        size = static_cast<int>(str.size());
        stringptr = new char[size];
        int index = 0;
        for (auto itr = str.begin(); itr != str.end(); ++itr)
        {
            stringptr[index] = *itr;
            index++;
        }
    }
    MyString(char *ptr = NULL)
    {
        cout << "Default constructor with ptr " ;
        if (ptr == NULL)
            cout << " NULL" <<endl;
        else
            cout << ptr << endl;
        stringptr = ptr;
        if (ptr == NULL)
            size = 0;
        else
            for(size=0; ptr[size]!=0; size++)
            {
                stringptr[size] = ptr[size];
            }
            
    }
    MyString(const MyString &mystr)
    {
        cout << "Copy constructor is evaluated " << endl;
        if (mystr.size == 0)
        {
            stringptr = NULL;
            size = 0;
            return;
        }
        
        size = mystr.size;
        stringptr = new char[size];
        for(int i = 0; i< size; i++)
        {
            stringptr[i] = mystr.stringptr[i];
        }
    }
    
    MyString & operator=(const MyString &old)
    {
        cout << " Operator = is evaluated" << endl;
        if (size != 0)
        {
            delete stringptr;
            size = 0;
            stringptr = NULL;
        }
        if (old.size == 0)
        {
            return *this;
        }
        size = old.size;
        stringptr = new char[size];
        for (int i = 0; i< size; i++)
        {
            stringptr[i] = old.stringptr[i];
        }
        return *this;
        
    }
    MyString & operator+(const MyString &old)
    {
        cout << " Operator + is evaluated" << endl;
        int newsize = size + old.size;
        if (newsize == 0)
        {
            return *(new MyString());
        }
        int index=0;
        MyString *ret = new MyString();
        ret->size = newsize;
        ret->stringptr = new char[newsize];
        if (size!=0)
        {
            for(index = 0; index < size; index ++)
            {
                ret->stringptr[index] = stringptr[index];
            }
            
        }
        if (old.size !=0)
        {
            for(int i = 0; i< old.size; i++)
            {
                ret->stringptr[index+i] = old.stringptr[i];
            }
        }
        return *ret;
    }
    MyString & operator+(string str)
    {
        cout << "Operator + with string is evaluated" << endl;
        MyString new1(str);
        return *this + new1;
        
    }
    
    void print()
    {
        if (stringptr != NULL)
        {
            for (int i = 0; i< size; i++)
            {
                cout << stringptr[i] ;
            }
            cout << endl;
        }
        else
            cout << "No String present" << endl;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    char ptr[] = "yahoo";
    char ptr1[] = "anz";
    MyString yahoo = ptr;
    MyString anz = ptr1;
    MyString z;
    yahoo.print();
    anz.print();
    z.print();
    z = yahoo+anz;
    z.print();
    MyString y = z;
    y.print();
    y = z;
    y.print();
    string simple1 = "simple";
    MyString simple = simple1;
    simple.print();
    char s[] = "kimple";
    MyString ym = s;
    MyString kimple = simple + ym;
    kimple.print();
    MyString yah;
    yah = simple + kimple;
    yah.print();
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

