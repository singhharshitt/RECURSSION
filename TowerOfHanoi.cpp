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

// #include <iostream>
// using namespace std;

// void towerofHanoi(int n, char source, char destination, char aux){
//     //if my sourrce have only one element then it will directly move to destnation
//     if(n==1){
//         cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
//         return;
//     }
//     //Now if i have more than one element the i have to shift from source to aux then then to destination
    
//     towerofHanoi(n-1, source, aux, destination);
//     cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
//     towerofHanoi(n-1, aux, destination, source);
// }
// int main(){
//     int n;
//     cout<<"Enter number of elements source has: ";
//     cin>>n;
//     towerofHanoi(n, 'A', 'B', 'C');
// }
