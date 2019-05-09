#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ld  long double
#define MAX 1000

using namespace std;


ld findDist(ld x1, ld y1, ld x2, ld y2){
    return (ld)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool isTouching(ld x1, ld y1, ld r1, ld x2, ld y2, ld r2){
    ld dist = findDist(x1, y1, x2, y2);
    if(abs(r1 - r2) <= dist  && dist <= abs(r1+r2))return true;
    return false;
}

void add(ll arr[], ll N, ll lo, ll hi, ll val)
{
    arr[lo] += val;
    if (hi != N - 1)
       arr[hi + 1] -= val;
}

void constructPrefix(ll arr[], ll N){
    for(ll i = 1; i < N; ++i){
        arr[i] += arr[i-1];
    }
}

void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int main()
{
    fast();
    ll n,q;
    cin >> n >> q;
    ld x[n];
    ld y[n];
    ld r[n];
    vector<pair<ll,ll>> v;
    ll k;
    ll maxcur;
    ll mincur;
    ll allmax = 0;

    for(ll i = 0; i < n; ++i){
        cin >> x[i];
        cin >> y[i];
        cin >> r[i];
    }

    for(ll i = 0; i < n-1; ++i){
        for(ll j = i+1; j < n; ++j){
            ld dist = findDist(x[i], y[i], x[j], y[j]);
            maxcur = (ll)floor(dist + r[i] + r[j]);

            if(isTouching(x[i], y[i], r[i], x[j], y[j], r[j])){    //intersect or overlap
                mincur = 0;
            }
            else if(dist > r[i] + r[j]){        //without
                mincur = (ll)ceil(dist - (r[i] + r[j]));
            }
            else if(dist < abs(r[i] - r[j])){       //within
                mincur = (ll)ceil(abs(r[i] - r[j]) - dist);
            }
            if(mincur <= maxcur)v.pb(mp(mincur,maxcur));
        }
    }
    ll arr[1000000] = {0};
    for(ll i = 0; i < v.size(); ++i){
        add(arr, allmax, v[i].first, v[i].second, (ll)1);
    }

    constructPrefix(arr, 1000000);

    for(ll i = 0; i < q; ++i){
        cin >> k;
        cout << arr[k] << endl;
    }

}

