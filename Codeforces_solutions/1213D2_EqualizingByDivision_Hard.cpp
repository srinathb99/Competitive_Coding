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
 
int main()
{
    fast();
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    LL t,n,i,j,k,x,y,c,m;
    cin >> n >> k;
    VL a(n);
    gall(a, n);
    sort(all(a));
    map<LL, MPLL> poss;
    map<LL, MSETL> poss1;
    REP(i, n){
        LL cur = a[i];
        LL temp = 0;
        while(cur > 0){
 
            poss1[cur].insert(temp++);
            cur /= 2;
        }
        poss1[0].insert(temp);
    }
    LL res = MAX;
    for(auto num : poss1){
 
        LL sum = 0;
        if(num.ss.size() >= k){
            LL i = 0;
            for(auto num1 : num.ss){
 
                sum += num1;
                ++i;
                if(i == k){
                    break;
                }
            }
 
            res = min(res, sum);
        }
    }
    cout << res << endl;
    
