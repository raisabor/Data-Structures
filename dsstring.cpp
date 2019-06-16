#include "dsstring.h"

DSString::DSString()
{



 len = 0;
 data = new char[1];
 data[0] = '\0';

}

DSString::DSString(const char* copy)
{




    if (copy)
    {
        int nope = 0;
        while (copy[nope] != '\0') nope++;
        len = nope;
        data   = new char[nope];
        for (int f=0; f < nope; f++)
            data[f] = copy[f];
    } else
    {
        len = 0;
        data   = new char[0];
    }


}


DSString::DSString(const DSString& gab) //copy constructor
{




    data = new char[gab.len + 1];
    strcpy(data, gab.data);
    len = gab.getlength();

}


DSString:: ~DSString()
{
delete[] data;
}




char* DSString::getData ( ) const  //returns the contents of string
{

    return data;
}

int DSString::getlength( ) const     //finds the length of string
{

    return len;

}

DSString& DSString::operator+=(const DSString& gab)
{

    int length = len + gab.getlength();
       char* trunk = new char[length];

       for (int k=0; k < len; k++)
           trunk[k] = data[k];

       for (int l=0; l < gab.getlength(); l++)
           trunk[len+ l] = gab[l];

       delete data;
       len = length;
       data   = trunk;
    return *this;
}

bool DSString::operator<(const DSString& mount) const  //boolean less than operator
{
    return strcmp(data,mount.getData()) < 0;


}

DSString DSString::operator+ (const DSString& right)
{
    DSString result(this-> data);
    result += right;
    return result;
}

DSString& DSString::operator=(const DSString& gab)  //compares two strings and sees if they are equal
{





   if(this == &gab) return *this;



   delete[] data;
   len = gab.getlength()+1;
   data = new char[len];

   for (int j=0; j < len; j++)
      data[j] = gab[j];

   return *this;




}




 DSString DSString::subtr(int positive,int space)
 {
    char* buffer = new char[space + 1];
    strncpy(buffer, this->data + positive, space);
    DSString temp(buffer);
    delete [] buffer;
    return temp;
 }

 int DSString::find(char* s) const
 {
     char* o = strstr(data, s);
     if (!o)
         return -1;
     return o - data;
 }




 ostream& operator<<(ostream& os, const DSString& s)
 {
     if (s.getlength() > 0)
     {
         for (int z=0; z < s.getlength(); z++)
             os << s[z];
     }
     else
        os << "";

     return os;

 }


 istream& operator>> (istream& is, DSString& s)
 {
     char* character = new char[1000];
      is >> character;
      s = DSString(character);
      delete[] character;

  return is;


 }


 char DSString::operator[] (int r) const
 {
     int i = r < 0 ? getlength() + r : r;
     return data[i];
 }


 char& DSString::operator[] (int r)
 {
     int i = r < 0 ? getlength() + r : r;

     return data[i];
 }


 bool DSString::operator== (const DSString& gab) const{

   if(strcmp(data,gab.data) == 0)
        return true;
   return false;





     /*
     if(len != gab.getlength()){
         return false;
     }
     int j = 0;

     while(j < getlength() && data[j] == gab.data[j]){
         ++j;
     }
     return j == getlength();
     */
 }

 bool DSString::operator!= (const DSString& gab)
 {

     int counter = 0;
     while (data[counter] != '\0')
     {
         if (data[counter] != gab.data[counter])
         {
             return true;
         }
         counter++;
     }
 return false;
 }




