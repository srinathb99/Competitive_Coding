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
    cin >> t;
    while( t-- ){
        cin >> n;
        LL a[n];
        gall(a, n);
        LL suff[n];
        suff[n - 1] = a[n - 1];
        for(LL i = n - 2; i >= 0; --i){
            suff[i] = min(a[i], suff[i + 1]);
        }
        c = 0;
        REP(i, n - 1){
            if(a[i] > suff[i + 1]){
                ++c;
            }
        }
        cout << c << endl;
    }
    
