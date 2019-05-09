#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;

int main(){
    ll x,n,m,i,sum = 0,maxx=0;
    ll maxa = 0,maxb = 0;
    cin >> n >> m;
    ll balloons[n];
    ll k;
    ll diff;
    vector<pair<ll,ll>> v;
    for(i = 0; i < n; ++i){
        cin >> balloons[i];
    }
    for(i = 0; i < n; ++i){
        cin >> x;
        v.pb(mp(balloons[i]*x,x));
    }
    sort(v.begin(), v.end());
    ll temp1 = 1000000000000000000;
    ll cost = 0;
    ll a = 0;
    ll b = 1000000000000000000;
    ll cur = b;
    ll temp = 0;
    while(a <= b){
        cost = 0;
        temp = 0;
        ll k = m;   
        cur = (a+b)/2;
        for(int i = 0; i < n; ++i){
            if(v[i].first - cur > 0){
                temp = (v[i].first - cur) /v[i].second;
                k -= temp;
                if((v[i].first - cur) % v[i].second != 0){
                    --k;
                }
            }
        }

        if(k >= 0){
            temp1 = cur;
            b = cur - 1;
        }
        else{
            a = cur + 1;
        }
    }
    cout << temp1 << endl;

}

