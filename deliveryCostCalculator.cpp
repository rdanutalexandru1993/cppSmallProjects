//================================================================================
//
// How to execute: sudo g++ -o homework_one homework_one.cpp to compile 
// ./homework_one -p            -> prints the prices 
// ./homework_one -i 4 10 22 44 -> passes the input for cost calculation
// ./homework_one -h            -> prints the help message 
 
#include <iostream>
#include <vector>
#include <string>

#define INFO 0
#define DEBUG 1
#define ERROR 2

void printHelp();
void startMessage();
void logMessage(int error, std::string msg);
void printPrices();
void calculateWeights(std::vector<int> &vect); 

int main(int argc, char* argv[]){
  startMessage();
  std::vector <int> input;
  for (int i = 1; i < argc; i++){
    std::string arg = argv[i];
    if((arg == "-h") || (arg == "--help")){
      printHelp();
      }else if((arg == "-p")||(arg == "--prices")){
        printPrices();
        }else if((arg == "-i")||(arg == "--input")){
          for(int j = ++i;j < argc;j++){
            input.push_back(std::stoi(argv[j]));
            i = j;
            };
          calculateWeights(input);
        }else{
          logMessage(ERROR,"Not yet implemented ...");
          };
    };

  return 0;
}

void startMessage(){
  //function to print header of the file 
  std::cout << "=========================================================================" << std::endl;
  std::cout << "---------------------------------- HEADER -------------------------------" << std::endl;
  std::cout << "  Program has been launched                                              " << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "=========================================================================" << std::endl;
};

void printPrices(){
  //function to print cost list 
  std::cout << "=========================================================================" << std::endl;
  std::cout << "------------------------------- COST LIST -------------------------------" << std::endl;
  std::cout << "  First KG _______________________________________________________13 GBP " << std::endl;
  std::cout << "  Each additional KG up to 5 KG ___________________________________6 GBP " << std::endl;
  std::cout << "  Each additional KG up to 10 KG __________________________________5 GBP " << std::endl;
  std::cout << "  Each additional KG over 10 KG ___________________________________4 GBP " << std::endl;
  std::cout << "                                                                         " << std::endl; 
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "=========================================================================" << std::endl; 
};

void printHelp(){
  //function to print help message on screen 
  std::cout << "=========================================================================" << std::endl;
  std::cout << "---------------------------------- HELP ---------------------------------" << std::endl;
  std::cout << "  This program calculates the cost of sending and airmail parcel from    " << std::endl; 
  std::cout << "  UK to Australia                                                        " << std::endl;
  std::cout << "                                                                         " << std::endl;
  std::cout << "  Available parameters:                                                  " << std::endl;
  std::cout << "                                                                         " << std::endl;
  std::cout << "  * [-p]|[--prices] -> prints the costs                                  " << std::endl;
  std::cout << "  * [-i]|[--input] -> specifies the input values                         " << std::endl;
  std::cout << "                                                                         " << std::endl;
  std::cout << "  The input parameters can be a list of values eg: 1 2 4 9               " << std::endl;
  std::cout << "  The output will be for each weight                                     " << std::endl;
  std::cout << "                                                                         " << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "=========================================================================" << std::endl;
};

void logMessage(int error, std::string msg){
  if(error == 0){
    std::cout << "[*INFO]| " << msg << std::endl;    
  }else if (error == 1) {
    std::cout << "[DEBUG]| " << msg << std::endl; 
  }else{
    std::cout << "[ERROR]| " << msg << std::endl;   
  };
};

void calculateWeights(std::vector<int> &vect){
  //function to calculate how much it costs for weights
  //logMessage(DEBUG,"Entered function calculate weights"); 
  std::cout << "=========================================================================" << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "  DISPLAYING SHIPPING COSTS                                              " << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "=========================================================================" << std::endl;
  int sum = 0;
  for (int i = 0; i < vect.size(); i++){
    //std::cout << " we are at index " << i << " and values is " << vect[i] << std::endl;
    if(vect[i] >= 10){
      sum = 13 + 4 * 6 + 5 * 5 + (vect[i]-10) * 4;  
    } else if ((vect[i] >= 5) && (vect[i] < 10)) {
      sum = 13 + 4 * 6 + (vect[i] - 5) * 5; 
    } else if ((vect[i] > 1) && ( vect[i] < 5)){
      sum = 13 + (vect[i] - 1) * 6;
    } else {
      sum = 13;
    };
    std::cout << "  Cost of sending " << vect[i] << "KG from UK to Australia is -> " << sum << std::endl; 
  };
  std::cout << "=========================================================================" << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "  END OF DISPLAY                                                         " << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "=========================================================================" << std::endl;
};
