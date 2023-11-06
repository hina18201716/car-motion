#include <iostream>
#include <fstream>
#include <iomanip>
#include "Vehicle.h"
#include "MathVector.h"
#include "State.h"
#include "Input.h"

using namespace std;

///////////////// Before submitting your code
//// 1) uncomment this part since zyBooks use it.
//int main(int argc, const char* argv[]) {
//    if (argc != 3)
//    {
//        std::cout << "./project2 inputFile outputFile" << std::endl;
//        return EXIT_FAILURE;
//    }
//    string inputFileName = argv[1];
//    string outputFileName = argv[2];
///////////////
//2) Comment the next 3 lines below
int main() {
    string inputFileName = "inputFile4.txt"; //DO NOT CHANGE "inputFileName"
    string outputFileName = "outputFile8.txt"; //DO NOT CHANGE "outputFileName"
    // Type your code here.
    
    ifstream inFile;
    ofstream outFile;
    
    inFile.open ( inputFileName );
    outFile.open( outputFileName );
    
    if( !inFile.is_open() ){
        cout << "file open error " << endl;
        return -1;
    }
  
    
    
    // read first 3 lines and assing each variable
    string linebase;
    string lineinitial;
    string linedt;
    
    //read from file
    getline(inFile, linebase);
    getline(inFile, lineinitial);
    getline(inFile, linedt);
    
    
    double wheelbase;
    string initialpose;
    double timedifference;
    
    //state
    State inital;
    inital.readElements( lineinitial );
    outFile << fixed << setprecision ( 3 );
    
    // wheelbase
    if( linebase.find(": ") != string::npos ){
        linebase = linebase.substr (linebase.find(": ")+2,linebase.size()-1);
    }
    wheelbase = stod( linebase );
    
    //time difference
    if( linedt.find(": ") != string::npos ){
        linedt = linedt.substr (linedt.find(": ")+2,linedt.size()-1);
    }
    timedifference = stod( linedt );
    
    
    Vehicle car( inital, wheelbase );
    //State* currstate = car.getState();
    
    // initial setup
    int count = 0 ; //how many steps
    outFile << count * timedifference << ",";
    outFile << car.getState()->getX() << "," << car.getState()->getY() << "," << car.getState()->getDelta() << "," << car.getState()->getTheta()  ;
    
    Input* move = new Input();
    string line;
    getline( inFile, line );
    
    //startmoving
    while ( !inFile.fail() && line!="" ){
        
            move->readElements( line );
            outFile << "," << move->getV() << "," << move->getDeltaDot();
            outFile << endl;

    
            car.update( move, timedifference );
            count ++ ;
           // currstate = car.getState();
            
            outFile << timedifference * count << ",";
            outFile << car.getState()->getX() << "," << car.getState()->getY() << "," << car.getState()->getDelta() << "," << car.getState()->getTheta()  ;
      
        
            getline( inFile, line );
    }
    
    outFile << endl;
    
    return 0;
    
  //  inFile.close();
    outFile.close();
}
    

