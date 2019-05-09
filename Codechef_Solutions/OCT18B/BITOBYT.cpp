#include<bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long int t,n,k,a,x,l,m;
    cin >> t;
    while( t-- ){
        cin >> n;
        k = n % 27;
        x = n / 27;
        a = pow(2,x);
        if(x == 0){
            if(k <= 2)cout<< a << " " << 0 << " " << 0;
            else if(k > 2 && k <= 10)cout << 0 << " " << a << " " << 0;
            else if(k > 10)cout << 0 << " " << 0 << " " << a;
        }
        else{
            m = (n - 1) / 26;
            a = pow(2, m);
            l = n % 26;
            if(l == 1 || l == 2)cout << a << " " << 0 << " " << 0;
            else if(l > 2 && l <= 10)cout << 0 << " " << a << " " << 0;
            else if(l > 10 || l == 0)cout << 0 << " " << 0 << " " << a;
        }
        cout << endl;
    }
}

