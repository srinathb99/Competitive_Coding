#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b,k,n;
    cin >> t;
    while( t-- ){
        cin >> a >> b >> k;
        n = (a + b) / k;
        if(n % 2 == 0)cout << "CHEF" << endl;
        else cout << "COOK" << endl;
    }

}
