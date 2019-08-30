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
#define MOD 100000000
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
 
LL dp[101][101][11][11];
 
int main()
{
    fast();
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    LL t,n,i,j,k,x,y,c,m;
    LL n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
     //dp[i][j][k][l] = number of arrangements when there are 'i'
    //horsemen remaining, j footmen remaining, can still add k horsemen and can still add
    // l footmen
    MEM(dp, 0);
    REP(i, n1 + 1){
        REP(j, n2 + 1){
            REP(k, k1 + 1){
                REP(l, k2 + 1){
                    LL ways = 0;
                    if(i + j == 0){
                        ways = 1;
                    }
                    else{
                        if(i > 0 && k > 0){
                            ways = dp[i - 1][j][k - 1][k2] % MOD;
                        }
                        if(j > 0 && l > 0){
                            ways = (ways + dp[i][j - 1][k1][l - 1]) % MOD;
                        }
                    }
                    dp[i][j][k][l] = ways % MOD;
                }
            }
        }
    }
    cout << dp[n1][n2][k1][k2];
