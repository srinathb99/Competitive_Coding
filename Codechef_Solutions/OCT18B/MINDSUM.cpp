#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;

ll digitSum(ll n){
    ll m = n;
    ll sum = 0;
    while( m != 0 ){
        sum += m % 10;
        m /= 10;
    }
    return sum;
}

vector<pair<ll,ll>> v;
map<ll,ll> visit;

void constructTree(ll n, ll d, ll i){
    if(i > 17)return;
    bool flag1 = false, flag2 = false;

    if(visit.find(n + d) == visit.end()){
        visit.insert(mp(n + d, i + 1));
        flag1 = true;
    }
    else{
        auto it = visit.find(n + d);
        if(it -> second > (i + 1)){
            visit.at(n+d) = (i + 1);
            flag1 = true;
        }

    }
    if(visit.find(digitSum(n)) == visit.end()){
        visit.insert(mp(digitSum(n), i + 1));
        flag2 = true;
    }
    else{
        auto it = visit.find(digitSum(n));
        if(it -> second > (i + 1)){
            visit.at(digitSum(n)) =  (i + 1);
            flag2 = true;
        }

    }
    if(flag1)constructTree(n + d, d, i + 1);
    if(flag2)constructTree(digitSum(n), d , i + 1);
}

ll findCount(ll n){
    if(n < 10)return 0;
    ll m = n;
    ll sum = 0;
    ll i = 1;
    while( m > 0 ){
        sum += m % 10;
        m /= 10;
    }
    if(sum >= 10){
        i = 1 + findCount(sum);
    }
    return i;
}
int main(){
    ll t,n,d,i,x,y;
    cin >> t;
    while( t-- ){
        cin >> n >> d;
        visit.insert(mp(n, 0));
        constructTree(n,d,0);
        ll k = v.size();
        auto it = visit.begin();
        if(visit.begin()->first == n)cout << n << " " << 0 << endl;
        else cout << visit.begin()->first << " " << visit.begin()->second << endl;
        visit.clear();

    }
    return 0;
}

