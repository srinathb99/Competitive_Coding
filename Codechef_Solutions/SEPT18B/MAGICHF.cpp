#include <iostream>
using namespace std;

int main() {
	int t,n,x,s,a,b;
	cin >> t;
	while(t--){
	    cin >> n;
	    cin >> x;
	    cin >> s;
	    while(s--){
	        cin >> a;
	        cin >> b;
	        if(a == x){
	            x = b;
	        }
	        else if(b == x){
	            x = a;
	        }
	    }
	    cout << x << endl;
	}
	return 0;
}
