// This generates the data in the input file
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream myfile ("data10m.bin",ios::binary | ios::trunc );
 
    srand(time(0));
    int dataSetSize = 10000000;
    for(int j=0; j<dataSetSize; j++){

        // Vector to store each datapoint of 100D
        vector<int> dataPoint;


         // Store the datapoint in the file
        int sizeD = 100;
        
        // This generates random no based on uniform distribution 
        unsigned seed = chrono::system_clock::now().time_since_epoch().count() + rand(); 
        default_random_engine generator(seed);
        normal_distribution<float> distribution(0.0, 100.0);

        // Filling values in the vector dataPoint
        for(int i=0; i<100; i++){
            dataPoint.push_back(distribution(generator));
        }

        if (myfile.is_open()){
            for(int count = 0; count < sizeD; count ++){
                myfile << dataPoint[count] << " " ;
            
            // myfile.write((char*) dataPoint, sizeof(datapoint))
            }
            myfile << endl;
            
        }
        else cout << "Unable to open file";
    }
    myfile.close();
    return 0;
}