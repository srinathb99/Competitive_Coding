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
    string str1, str2;
    cin >> str1 >> str2;
    n = str1.size();
    SETL s;
    for(LL i = 1; i * i <= n; ++i){
        if(n % i == 0){
            s.insert(i);
            s.insert(n / i);
        }
    }
    VL prefsizes;
    for(auto num : s){
        prefsizes.PB(num);
    }
    VS prefs;
    k = 0;
    string str = "";
    REP(i, n){
        str += str1[i];
        if(i + 1 == prefsizes[k]){
            prefs.PB(str);
            ++k;
            if(k == prefsizes.size()){
                break;
            }
        }
    }
 
    map<string, LL> mpp;
    REP(i, prefs.size()){
        str = prefs[i];
        bool ok = true;
        REP(j, n){
            if(str1[j % str.size()] != str1[j]){
                ok = false;
            }
        }
        if(ok){
            mpp[str]++;
        }
    }
    
    n = str2.size();
    s.clear();
    for(LL i = 1; i * i <= n; ++i){
        if(n % i == 0){
            s.insert(i);
            s.insert(n / i);
        }
    }
    prefsizes.clear();
    for(auto num : s){
        prefsizes.PB(num);
    }
    prefs.clear();
    k = 0;
    str = "";
    REP(i, n){
        str += str2[i];
        if(i + 1 == prefsizes[k]){
            prefs.PB(str);
            ++k;
            if(k == prefsizes.size()){
                break;
            }
        }
    }
 
    REP(i, prefs.size()){
        str = prefs[i];
        bool ok = true;
        REP(j, n){
            if(str2[j % str.size()] != str2[j]){
                ok = false;
            }
        }
        if(ok){
            mpp[str]++;
        }
    }
 
    LL res = 0;
    for(auto p : mpp){
        if(p.ss == 2){
            ++res;
        }
    }
    cout << res;
    
