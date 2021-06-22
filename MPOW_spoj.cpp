//problem https://www.spoj.com/problems/MPOW/
#include<iostream>
#define M 51

using ll = long long;
unsigned int mod = 1000000007;
using namespace std;
ll arr[M][M], I[M][M];

void display(ll ar[][M],unsigned int r){unsigned int i=0,j=0;
    for (i = 0; i <r; i++){
        for ( j = 0; j <r; j++){
            cout<<ar[i][j]<<" ";
        }printf("\n");
    }
}

void multiply(ll ar1[][M],ll ar2[][M],unsigned int r){unsigned int i=0,j=0,k=0;
    ll res[r][r];
    for (i = 0; i <r; i++){
        for (j = 0; j <r; j++){res[i][j]=0;
            for (k = 0; k <r; k++){
                res[i][j] = (res[i][j] + ((ar1[i][k] * ar2[k][j]) % mod))%mod;
            }
        }
    }
    for (i = 0; i < r; i++){
        for (j= 0; j < r; j++){
            ar1[i][j]=res[i][j];
        } 
    }
}
void NPOW(unsigned int m,unsigned int n){
    while (n){
        if(n%2){
            multiply(I,arr,m);
            n--;
        }else{
            multiply(arr,arr,m);
            n=n/2;
        }
    }
    display(I,m);    
}

int main(){unsigned int t=0;
    cin>>t;
    while (t--){
        unsigned int i=0,n=0,m=0;
        cin>>m>>n;
        while (i<m){unsigned int j=0;
            while(j<m){
                if(i==j){I[i][j]=1;}else{I[i][j]=0;}
                cin>>arr[i][j++];
            }i++;
        }
        NPOW(m,n);
    }
    return 0;
}
