/* 
    @author : srinathbalaji_99
*/
 
 
#include<bits/stdc++.h>
 
#define PB push_back
#define MP make_pair
#define endl '\n'
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define rep(i, a, b, inc) for(long long i = a; i < b; i += inc)
#define REP(i, n) rep(i, 0, n, 1)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define PLL pair<long long, long long>
#define VL vector<long long>
#define VS vector<string>
#define VLL vector<PLL>
#define VVL vector<VL>
#define MPLL map<long long, long long>
#define UMPLL unordered_map<long long, long long>
#define SETL set<long long>
#define MSETL multiset<long long>
#define GCD(a, b) __gcd(a, b)
#define LCM(a, b) (a * b)/GCD(a, b)
#define ff first
#define ss second
#define pall(a) REP(i, sizeof(a)/sizeof(a[0]))cout << a[i] << " ";cout << endl;
#define pvall(v) REP(i, v.size())cout << v[i] << " ";cout << endl;
#define gall(a, n) REP(i, n)cin >> a[i];
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
 
 
using namespace std;
 
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
LL parents[200001];
LL sizes[200001];
 
LL findset(LL x){
    if(x == parents[x]){
        return x;
    }
    return parents[x] = findset(parents[x]);
}
 
LL merge(LL x, LL y, LL res){
    x = findset(x);
    y = findset(y);
    if(x == y){
        return 0;
    }
    if(sizes[y] > sizes[x]){
        swap(x, y);
    }
    res = res - ((sizes[x] * (sizes[x] - 1)) / 2) - ((sizes[y] * (sizes[y] - 1)) / 2);
    parents[y] = x;
    sizes[x] += sizes[y];
    res += ((sizes[x] * (sizes[x] - 1)) / 2);
    return res;
}
 
int main()
{
    fast();
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    LL t,n,i,j,k,x,y,c,m;
    cin >> n >> k;
    if(n == 1){
        REP(i, k){
            cout << 0 << " ";
        }
        cout << endl;
        return 0;
    }
    vector<pair<LL, PLL>> edges(n - 1);
    REP(i, n - 1){
        cin >> edges[i].ss.ff >> edges[i].ss.ss >> edges[i].ff;
        edges[i].ss.ff--;
        edges[i].ss.ss--;
    }
    REP(i, n){
        parents[i] = i;
        sizes[i] = 1;
    }
    sort(all(edges));
    VL q(k);
    REP(i, k){
        cin >> q[i];
    }
    VL fin = q;
    sort(all(q));
    LL res = 0;
    j = 0;
    MPLL ans;
    REP(i, k){
        LL curwt = q[i];
        while(edges[j].ff <= curwt && j < n - 1){
            res = merge(edges[j].ss.ff, edges[j].ss.ss, res);
            ++j;
            
        }
        
        ans[q[i]] = res;
    }
    REP(i, fin.size()){
        cout << ans[fin[i]] << " ";
    }
    cout << endl;
