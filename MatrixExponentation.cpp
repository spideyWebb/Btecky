#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define sz 2

struct Mat{
    int m[sz][sz];
    Mat(){
        memset(m, 0, sizeof(m));
    }

    void identity(){
        for(int i = 0; i < sz; i++){
            m[i][i] = 1;
        }
    }

    Mat operator*(Mat a){
        Mat res;
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                for(int k = 0; k < sz; k++){
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

int fib(int n){
    Mat res;
    res.identity();
    Mat T;
    T.m[0][0] = 1;
    T.m[0][1] = 1;
    T.m[1][0] = 1;

    if(n <= 2){
        return 1;
    }

    n -= 2;

    while(n){
        if(n & 1){
            res = res * T;
        }
        T = T * T;
        n = n >> 1;
    }
    return (res.m[0][0] + res.m[0][1]) % mod;
}

int main()
{
    int n = 5;
    cout << fib(n) << endl;
    return 0;
}

