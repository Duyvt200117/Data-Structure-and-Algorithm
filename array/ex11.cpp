'''Given two sorted arrays X[] and Y[] of size m and n each where m >= n and X[] has exactly n vacant cells,
merge elements of Y[] in their correct position in array X[], i.e., merge (X, Y) by keeping the sorted order'''

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int array1[] = {0, 2, 0, 3, 0, 5, 6, 0, 0};
    int array2[] = {1, 8, 9, 10, 15};

     int size1 = sizeof array1,  length1 = sizeof array1/ sizeof(int); 
     int size2 = sizeof array2,  length2 = sizeof array2/ sizeof(int); 


    int result[length1 + length2];
     
    memcpy(result,array1,size1);  
    
    memcpy(&result[length1],array2,size2); 

    for(short i = 0; i < 14; i++) {
      cout << result[i]<<' ';
    }   
}

