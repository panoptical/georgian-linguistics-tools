
#include "kartio.h"
using namespace std;

//bool iska(char c)
//returns true if c is an internal Georgian character
//otherwise returns false
bool iska(char c){
    if ((c >= (char)144)&&(c <= (char)176))
    {
        return true;
    }
    else
    {   
        return false;
    }
}

char kar (string s)
{
    return dekart(s)[0];
}

string dekart (string s){
    string result = "";
    char fi = FIR;
    char se = SEC;
    for (int i=0; i<s.size(); i++)
    {
        
        if (s[i] == fi){
            if (iska(s[i+2]))
            {
                s.erase(i, 2);
            }
        }
        result += s[i];
    }
    return result;
}

string rekart (string s)
{
    string result = "";
    char fi = FIR;
    char se = SEC;
    string fise = "";
    fise += fi; fise += se;
    
    for (int i=0; i<s.size(); i++)
    {
        
        if (iska(s[i])){
            result += fise;
        }
        result += s[i];
    }
    return result;
    
}

//keytrans takes a string of characters and replaces any Georgian characters 
//  with their Latin equivalents.  All other characters are left alone.
string keytrans(string s)
{
    char transc[] = "abgdevzTiklmnopJrstufqRuSCcZwWxjh";
    string result;
    for (int i=0; i<s.size(); i++)
    {
        if (iska(s[i]))
        {
            result += transc[int(s[i])+112];
        }
        else
        {
            result += s[i];
        }    
    }
    return result;
}


//detrans looks at a string and replaces the characters a-zWRTSJZC with their
//Georgian equivalents.  All other characters are left alone.
//The translation string contains the ASCII characters in between the Georgian 
//  characters so that they will be replaced with themselves if there is no 
//  Georgian equivalent: A will be replaced with A, B with B, C with ჩ, etc.
string detrans(string s){
    string transs=dekart("ABჩDEFGHIჟKLMNOPQღშთUVჭXYძ[\\]^_`აბცდეფგჰიჯკლმნოპქრსტუვწხყზ");
    string result;
    for (int i=0; i<s.size(); i++)
    {
        if ((s[i] >= 'A')&&(s[i]<='z')) //if it's a letter
        {
            result += transs[int(s[i])-65]; //add the corresponding Georgian character to the result
        }
        else
        {
            result += s[i]; //otherwise just keep the character as is
        }    
    }
    return result;


}


