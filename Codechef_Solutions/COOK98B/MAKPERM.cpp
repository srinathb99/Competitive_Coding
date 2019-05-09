#include <bits/stdc++.h>
using namespace std;

int main() {

	long int n,t,i,sum,x,max;
	cin >> t;
	while(t--){
	    max = 0;
	    sum = 0;
	    cin >> n;
	    unordered_map<int,int> map;
	    for(i = 0; i < n; ++i){
	        cin >> x;
	        if(map.count(x) == 0 && x <= n){
	            map.insert(make_pair<int,int>(x,1));
	        }
	        else{
	                sum++;
	        }
	    }
	    cout << sum << endl;
	}
	return 0;
}

