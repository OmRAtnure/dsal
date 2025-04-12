#include<iostream>
#include <iomanip>
using namespace std;

void makeGraph(string cities[],int **graph,int size){
// int  size=sizeof(graph[0])/sizeof(graph[0][0]);
int fuel;
for(int i=0;i<size;i++){
    for(int j=i;j<size;j++){
        cout<<"enter fuel to go from "<<cities[i]<<" to "<<cities[j]<<" ";
        cin>>fuel;
        graph[i][j]=fuel;
        graph[j][i]=fuel;
    }
}
}

void printgraph(string cities[],int **graph,int size) {
    // int  size=sizeof(graph[0])/sizeof(graph[0][0]);
    cout<<setw(8)<<"  ";
    for(int i=0;i<size;i++) {
        cout<<setw(6)<<cities[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<size;i++) {
        cout<<setw(6)<<cities[i]<<' ';
        for(int j=0;j<size;j++){
            cout<<setw(6)<<graph[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int noOfCites;
    cout<<"Enter number of cites: ";
    cin>>noOfCites;
    string cities[noOfCites];
    int **graph=new int*[noOfCites];
    for (int i = 0; i < noOfCites; i++) {
        graph[i] = new int[noOfCites];  
    }


    
    for(int i=0;i<noOfCites;i++){
         cout<<"enter city name: ";
         cin>>cities[i];
    }
    makeGraph(cities,graph,noOfCites);
    printgraph(cities,graph,noOfCites);
    
    return 0;
}


