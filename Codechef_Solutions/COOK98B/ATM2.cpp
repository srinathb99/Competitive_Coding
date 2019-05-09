#include <iostream>
using namespace std;

int main() {

	int n,t,k,i,val;
	cin >> t;
	while(t--){
	    cin >> n >> k;
	    for(i = 0; i < n; ++i){
	        cin >> val;
	        if(val <= k){
	            cout<<1;
	            k -= val;
	        }
	        else{
	            cout<<0;
	        }
	        
	    }
	    cout<<endl;
	}
	return 0;
}
