#include <iostream>
using namespace std;

int main() {
	long int t,n,i,x;
	
	cin >> t;
	while(t--){
	    long int a[1000001];
	    for(i = 0; i < 1000001; ++i){
	        a[i] = 0;
	    }
	    long int odd = 0,even = 0,oddsum = 0,evensum = 0,tillsum = 0,oddmax=1,evenmax=2;
	    cin >> n;
	    for(i = 0; i < n; ++i){
	        cin >> x;
	        if(x % 2 == 0){
	            a[x]++;
	            if(x > evenmax)evenmax = x;
	            even++;
	        }
	        else{
	            a[x]++;
	            if(x > oddmax)oddmax = x;
	            odd++;
	        }
	    }
	    for(i = 1; i <= oddmax; i+=2){
	        tillsum += a[i];
	        oddsum += a[i]*(odd - tillsum);
	    }
	    tillsum = 0;
	    for(i = 2; i <= evenmax; i+=2){
	        tillsum += a[i];
	        evensum += a[i]*(even - tillsum);
	    }
	    for(i = 1; i <= oddmax-1; i+=4){
	        oddsum -= a[i]*a[i+2];
	    }
	    for(i = 4; i <= evenmax-1; i+=4){
	        evensum -= a[i]*a[i+2];
	    }
	    cout << oddsum+evensum <<endl;
	}
	return 0;
}

