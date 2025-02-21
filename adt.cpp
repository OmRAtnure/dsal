#include <iostream>
#include<vector>
#include<utility>
using namespace std;

class Dictionry{
    static const int size;
    vector <pair<int,string>> *dict;
    public:
    Dictionry(int size){
        dict= new vector<pair<int, string>> [size];
    }
    int hashfunction(int key){
        return key%10;
    }

    void insert(int key,string value){
        int index=hashfunction(key);
        dict[index].push_back({key,value});
        cout<<"inserted: "<<value<<endl;
    }
    
    void find(int key){
        int index=hashfunction(key);
        for(auto pair:dict[key]){
            if(pair.first==key){
                cout<<"Key found, value: "<<pair.second<<endl;
                return;
            }
        }
        cout<<"Key not found";
    }

    void remove(int key){
        int index =hashfunction(key);
        for (auto it = dict[index].begin(); it != dict[index].end(); it++){
            if(it->first==key){
                dict[index].erase(it);
                cout<<"deleted"<<endl;
                return;
            }
        }         
    }
};

int main(){
    Dictionry dict(10);
    dict.insert(5,"om");
    dict.find(5);
    dict.remove(5);
    dict.find(5);

    return 0;
}
