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
 
VVL adj;
LL dist[100001][101];
 
void bfs(VL& v, LL type){
    queue<LL> q;
 
    for(auto num : v){
        q.push(num);
        dist[num][type] = 0;
    }
    while(!q.empty()){
        LL node = q.front();
 
        q.pop();
        for(auto next : adj[node]){
            if(dist[next][type] <= dist[node][type] + 1){
                continue;
            }
            else{
                dist[next][type] = dist[node][type] + 1;
                q.push(next);
            }
        }
    }
}
 
int main()
{
    fast();
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    LL t,n,i,j,k,x,y,c,m;
    LL s;
    cin >> n >> m >> k >> s;
    LL a[n];
    REP(i, n){
        REP(j, k + 1){
            dist[i][j] = MAX;
        }
    }
    gall(a, n);
    adj.resize(n);
    REP(i, m){
        cin >> x >> y;
        x--;
        y--;
        adj[x].PB(y);
        adj[y].PB(x);
    }
 
    VVL prods(k + 1);
 
    REP(i, n){
        prods[a[i]].PB(i);
    }
 
    
 
    REP(i, k + 1){
        if(i == 0){
            continue;
        }
        bfs(prods[i], i);
 
    }
    VL res;
    REP(i, n){
        VL temp;
        rep(j, 1, k + 1, 1){
            temp.PB(dist[i][j]);
        }
        sort(all(temp));
        LL sum = 0;
        REP(j, s){
            sum += temp[j];
        }
        res.PB(sum);
    }
    pvall(res);
}
