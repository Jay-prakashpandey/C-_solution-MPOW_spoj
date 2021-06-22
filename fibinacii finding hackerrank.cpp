//problem: https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem
#include <bits/stdc++.h>
#define mod 1000000007
using ll= long long;
using namespace std;

ll I[2][2],T[2][2];

void multiply(ll ar1[][2],ll ar2[][2]){ll i=0,j=0,k=0;
    ll res[2][2];
    for (i = 0; i <2; i++){
        for (j = 0; j <2; j++){res[i][j]=0;
            for (k = 0; k <2; k++){
                ll x = (ar1[i][k]*ar2[k][j])%mod;
                res[i][j] = (res[i][j] + x )%mod;
            }
        }
    }
    for (i = 0; i < 2; i++){
        for (j= 0; j < 2; j++){
            ar1[i][j]=res[i][j];
        } 
    }
}

int solve(int a, int b, int n) {
    if(n<3){
        return n==1?b:b+a ;
    }
    I[0][0]=I[1][1]=T[0][1]=T[1][0]=T[1][1]=1;
    I[0][1]=I[1][0]=T[0][0]=0;
    while (n){
        if(n%2){
            multiply(I,T);
            n--;
        }else{
            multiply(T,T);
            n=n/2;
        }
    }
    return (a*I[0][0] + b*I[1][0])%mod;
}

int main()
{   int t;
    cin>>t;
    while(t--){
        int a,b,n,result;
        cin>>a>>b>>n;
        result = solve(a, b, n);
        cout << result << "\n";
    }
    return 0;
}
