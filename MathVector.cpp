#include "MathVector.h"
#include <string>
#include <iomanip>

using namespace std;

//default contructor
//MathVector();   //set numElements to 0, then resize the vector "elements" with numElements
    MathVector::MathVector(){ numElements = 0; elements.resize( numElements ); };

//parameterized contructor
//MathVector(int num_entered); //set numElements to num_entered, then resize the vector "elements" with numElements

MathVector::MathVector( int usersize ){ numElements = usersize; elements.resize( usersize ); };

//~MathVector() { }  //no code needed inside this destructor
   MathVector::~MathVector(){ };


//Given a string consisting of xx, xx, xx (each value seperated by comma)
//extract each value to populate the elements vector
//return true if a string is valid, false if invalid.
//bool readElements(string str);
//
bool MathVector::readElements( string str ){
    int i = 0;
    int count = 2;
    string in;
    
    //for initial position
    if( str.find(": ") != string::npos ){
        str = str.substr (str.find(": ")+2,str.size());
        count = 4;
    }
    while (str.find(",") != string::npos){
        in = str.substr(0,str.find(","));
        elements.at(i) = stod( in );
        i ++ ;
        str = str.substr(str.find(",") + 1, str.size() );
        
    }
    elements.at(i) = stod( str );
    
    
    //for others
    while (str.find(", ") != string::npos){
        in = str.substr(0,str.find(", "));
        elements.at(i) = stod( in );
        i ++ ;
        str = str.substr(str.find(", ") + 2, str.size() );
        
    }
    elements.at(i) = stod( str );
    if ( i == count ){
        return true;
    }
    else{
        return false;
    }
    
}

//to output a string using data in elements vector.
//string is in the format aa, bb, cc, ... , ss
//For examples, given the vector elements of 0.1 0.2 0.3 0.5
//this funciton returns a string 0.100,0.200,0.300,0.500
//DO NOT add a new line at the end.
//string toString();
    
std::string MathVector::toString( ) {
    int i;
    string line;
    for (i=0; i< elements.size()-1 ; i++){
        line = to_string( elements.at(i) ) + ", ";
    }
    line = to_string(i);
    
    return line;
};
