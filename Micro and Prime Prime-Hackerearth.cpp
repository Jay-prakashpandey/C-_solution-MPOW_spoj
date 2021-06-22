// problem https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/
#include<bits/stdc++.h>
using namespace std;
#define max 1000001

#define REP(i,k) for(i=0;i<=k;i++)

bool ar[max];
int pp[max];
void sieve(){int i=0;
    REP(i,max) ar[i]=1;
    ar[0]=ar[1]=0;
    for(int i=2;i*i<=max;i++){
        if(ar[i]==1){
            for(int j=i*i;j<=max;j+=i){
                ar[j]=0;
            }
        }
    }
    int cnt=0;
    REP(i,max){
        if(ar[i]==1){
            cnt++;
        }if(ar[cnt]==1){
            pp[i]=1;
        }
        else{
            pp[i] = 0; 
        }
    }
    REP(i,max)
    pp[i]+=pp[i-1];
}


int main(){
    sieve();
    int n,a,b,cnt=0;
    cin>>n;
    while (n--){
        cin>>a>>b;
        cnt=pp[b]-pp[a-1];
        cout<<cnt<<endl;
    }
    return 0;
}