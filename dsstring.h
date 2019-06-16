#ifndef DSSTRING_H
#define DSSTRING_H
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

class DSString
{
private:
    char* data;
    int len;

public:
    DSString();
    DSString(const DSString&);
    DSString& operator=(const DSString&);
    DSString (const char*);
    ~DSString();
    DSString& operator+= (const DSString&);
    char* getData() const;
    int getlength() const;
    DSString subtr(int,int);
    int find(char*) const;
    bool operator< (const DSString&) const;
    DSString operator+(const DSString&);
    char& operator[] (int);
    char operator[] (int) const;
    bool operator== (const DSString&) const;
    friend ostream& operator<<(ostream&, const DSString&);
    friend istream& operator>> (istream& is, DSString&);
    bool operator!=(const DSString&);


};


#endif // DSSTRING_H
