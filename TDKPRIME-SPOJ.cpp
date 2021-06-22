// problem https://www.spoj.com/problems/TDKPRIME/
#include<iostream>
#include<vector>
#define max 87000008

using namespace std;
vector<unsigned int>prime;
bool res[max];

void Kth_prime(){unsigned int i=0,j=0;
    res[0]=res[1]=true;
    for(i=2;i*i<=max;i++){
        if(!res[i]){
            for(j=i*i;j<=max;j+=i){
                res[j]=true;
            }
        }
    }
    for (i = 2; i < max; i++){
        if(!res[i]){
            prime.push_back(i);
        }
    }
}
int main(){
    unsigned int n,t;
    cin>>n;

    Kth_prime();
    while (n--){
    cin>>t,cout<<prime[t-1]<<endl;}
    return 0;
}