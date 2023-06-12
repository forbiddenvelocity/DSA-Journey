#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
const int TABLE_SIZE = 10

class HashTable {
    private:
        int table[TABLE_SIZE];
        bool isOccupied[TABLE_SIZE];
    public:
        HashTable(){
            for(int i=0; i<TABLE_SIZE; i++){
                table[i] = -1;
                isOccupied[i] = false;
            }
        }

        int hashFunction(int key){
            return key%TABLE_SIZE;
        }

        int quadraticProbing(int key, int i){
            return (hahsFunction(key)+i*i)%TABLE_SIZE;
        }

        int insert(int key){
            int index = hashFunction(key);
            if(!isOccupied[index]){
                table[index] = key;
                isOccupied[index] = false;
            }
            else{
                int i=1;
                int newIndex = quadraticProbing(key, i);
                while(!isoccupied[newIndex]){
                    table[newIndex]=key;
                    isOcuppied[index]=true;
                    break;
                }
                i++;
            }
        }
};

int main(){
    
    return 0;
}