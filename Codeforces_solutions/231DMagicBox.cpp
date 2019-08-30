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

LL dotproduct(VL& a, VL& b){
    LL sum = 0;
    REP(i, a.size()){
        sum += a[i] * b[i];
    }
    return sum;
}

int main()
{
    fast();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    LL px, py, pz;
    LL x, y, z;
    cin >> px >> py >> pz >> x >> y >> z;
    px *= 2;
    py *= 2;
    pz *= 2;
    x *= 2;
    y *= 2;
    z *= 2;
    LL a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    LL res = 0;
    //a1 = ZOX, normal vector = (0, -1, 0)
    //a2 || ZOX, normal vector = (0, 1, 0)
    //a3 = XOY, normal vector = (0, 0, -1)
    //a4 || XOY, n.v = (0, 0, 1)
    //a5 = YOZ, n.v = (-1, 0, 0)
    //a6 || YOZ, n.v = (1, 0, 0)
    
    VL zoxnv = {0, -1, 0};
    VL zox2nv = {0, 1, 0};
    VL xoynv = {0, 0, -1};
    VL xoy2nv = {0, 0, 1};
    VL yoznv = {-1, 0, 0};
    VL yoz2nv = {1, 0, 0};

    VL seezox = {px - (x / 2), py, pz - (z / 2)};
    if(dotproduct(seezox, zoxnv) > 0){
        res += a1;
    }

    VL seezox2 = {px - (x / 2), py - y, pz - (z / 2)};
    if(dotproduct(seezox2, zox2nv) > 0){
        res += a2;
    }

    VL seexoy = {px - (x / 2), py - (y / 2), pz};
    if(dotproduct(seexoy, xoynv) > 0){
        res += a3;
    }

    VL seexoy2 = {px - (x / 2), py - (y / 2), pz - z};
    if(dotproduct(seexoy2, xoy2nv) > 0){
        res += a4;
    }

    VL seeyoz = {px , py - (y / 2), pz - (z / 2)};
    if(dotproduct(seeyoz, yoznv) > 0){
        res += a5;
    }

    VL seeyoz2 = {px - x, py - (y / 2), pz - (z / 2)};
    if(dotproduct(seeyoz2, yoz2nv) > 0){
        res += a6;
    }

    cout << res;


}
