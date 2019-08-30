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
 
    LL t,n,i,j,k,x,y,m;
    cin >> n;
    LL c[n];
    gall(c, n);
    VS v;
    string str;
    REP(i, n){
        cin >> str;
        v.PB(str);
    }
    LL dp[n][2]; //dp[i][0] = mincost to sort first i + 1 strings, i + 1-th string hasnt been reversed
                //dp[i][1] = similar, but i + 1-th string is reversed
 
    REP(i, n){
        dp[i][0] = MAX;
        dp[i][1] = MAX;
    }
 
    dp[0][0] = 0;
    dp[0][1] = c[0];
    bool ok = true;
 
    REP(i, n){
        if(i == 0){
            continue;
        }
        bool ok1 = false, ok2 = false;
        string revprev = v[i - 1];
        reverse(all(revprev));
 
        if(v[i] >= v[i - 1] && dp[i - 1][0] != -1){
            dp[i][0] = dp[i - 1][0];
            ok1 = true;
        }
        string rev = v[i];
        reverse(all(rev));
        
        if(rev >= v[i - 1] && dp[i - 1][0] != -1){
            dp[i][1] = (dp[i - 1][0]) + c[i];
            ok2 = true;
        }
        if(rev >= revprev && dp[i - 1][1] != -1){
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
            ok2 = true;
        }
        if(v[i] >= revprev && dp[i - 1][1] != -1){
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            ok1 = true;
        }
        if(!ok1){
            dp[i][0] = -1;
        }
        if(!ok2){
            dp[i][1] = -1;
        }
        if(!(ok1 || ok2)){
            ok = false;
            break;
        }
    }
 
    if(ok){
        if(dp[n - 1][0] == -1){
            dp[n - 1][0] = MAX;
        }
        if(dp[n - 1][1] == -1){
            dp[n - 1][1] = MAX;
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]);
    }
    else{
        cout << -1;
    }
}
