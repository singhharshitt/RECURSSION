#include <iostream>

using namespace std;
void toh(int n, char source, char destination, char auxilary){
    if(n==0){
        return;
    }
    //Move n-1 block from source to destination
    toh(n-1,source, auxilary, destination);
    cout<<"Move from "<<source<<" to "<<destination<<endl;
    //move n-1 block fro0m auxilary to destination
    toh(n-1, auxilary, destination, source);
}
int main(){
    int n;
    cout<<"Enter number of Disks: ";
    cin>>n;
    toh(n,'A', 'C', 'B');
    return 0;
}
