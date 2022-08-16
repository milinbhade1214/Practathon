#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <vector>
#include <limits.h>
#include <chrono>
#include <time.h>
#include <cstdlib>
#include <algorithm>
// using std::cerr;
using std::ifstream;
using namespace std::chrono;
using namespace std;

vector<vector<int> > dataset;

void print(vector<int> const &a) {
   for(int i=0; i < a.size(); i++)
    cout << a.at(i) << ' ';
}

template <typename T> 
void print(T arr[], int size){
    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int euclideanDistance(vector<int> &v1, vector<int> &v2){
    int sum = 0;
    for(int i=0; i<100; i++){
        sum += pow(v2[i] - v1[i], 2);
    }
    return sum;

}

int findSmallest(vector<int> &arr, int size){
    int smallest = INT_MAX;
    int index = 0;
    for(int i=0; i<size; i++){
        if(arr.at(i) < smallest){
            smallest = arr[i];
            index  = i;
        }
    }
    return index;
} 

// void generateDistances(vector<int> &distances,vector<int> &query, vector<vector<int>> &dataset){
//     for(size_t a = 0; a < dataset.size(); a++){
//         int dis = euclideanDistance(query, dataset.at(a));
//         distances.push_back(dis);
//     }
// }



// void getNearestNeighbour(vector<int> &distances, int tenNearest[], int dataSetSize){
//     // cout << "Distances : " << endl;
//     // print(distances);
//     // cout << endl << "--------------------------------------------------------------------" << endl;

//     int infi = INT_MAX;

//     for(int i=0; i<10; i++){
//         int ind = findSmallest(distances, dataSetSize);
//         distances[ind] = infi;
//         tenNearest[i] = ind;
//     }
// }

void generateQuery(vector<int> &query){
    // This generates random no based on uniform distribution 
    unsigned seed = chrono::system_clock::now().time_since_epoch().count() + rand(); 
    default_random_engine generator(seed);
    normal_distribution <float> distribution(0.0, 100.0);

 // Filling values in the vector dataPoint
    for(int i=0; i<100; i++){
        query.push_back(distribution(generator));
    }
}


int main(){

	int dataSetSize = 10000000;
    int dim = 100;
    int queryTime[101];

    
	// Get Data in vectors
	ifstream inputfile("data10m.bin", ios::in);
	vector<int> distances;

	if(inputfile){
		for(int i=0; i< dataSetSize; i++){
            vector<int> dataPoint;
            int data;
            for(int c=0; c< dim; c++){
                inputfile >> data;
                dataPoint.push_back(data);
            }
            dataset.push_back(dataPoint);
		}		
		inputfile.close();
	}else{
		cout << "Error opening the file";
	}
	
    cout << "DataSet Size :" << dataset.size() << endl;

    for (int i = 0; i < 101; ++i){
        vector<int> query;
        generateQuery(query);

        cout << "Query"<< i << ": "<< endl;
        print(query);
        cout <<endl << "-----------------------------------------------------------------------------" << endl;


        auto start = high_resolution_clock::now();
        // generateDistances(distances, query, dataset);
        for(size_t a = 0; a < dataSetSize; a++){
            int dis = euclideanDistance(query, dataset.at(a));
            distances.push_back(dis);
        }

    	int tenNearest[10];
        // getNearestNeighbour(distances, tenNearest, dataSetSize);
        int infi = INT_MAX;

        for(int i=0; i<10; i++){
            int ind = findSmallest(distances, dataSetSize);
            distances[ind] = infi;
            tenNearest[i] = ind;
        }    


        cout << "Following are the indices of 10 nearest point : " << endl;
        print<int>(tenNearest, 10);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
     
    	// To get the value of duration use the count()
    	// member function on the duration object
    	cout <<"Time Elapsed: " <<duration.count() << endl;

        queryTime[i] = duration.count();
    }

    print<int>(queryTime, 101);
    sort(queryTime, queryTime + 101);

    cout << "Median Time : " << queryTime[50] << endl;
}