//Mark XXVII
#include<bits/stdc++.h>

#define big(x) greater<x>()
#define ll long long int
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define PI 3.14159265
#define deb(x) cerr<<#x<<" : "<<x<<"\n";
#define deball(x) for(auto iit:x) cerr<<iit<<" ";cerr<<"\n";
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,b,c) for(i=b; i<c; ++i)
#define rrep(i,b,c) for(i=b; i>=c; --i)

#define M 998244353
#define LINF 1e18
#define INF INT_MAX
using namespace std;

ll i, j, n, k, z;
vector<vector<int> > adj;
vector<int> vis;
map< pair<int, int>, ll > w;
ll tot = 0;

struct comp {
  bool operator() (const pair<ll,ll>& p1, const pair<ll,ll>& p2) const {
    if(p1.first*p1.second> p2.first*p2.second) return true;
    else return false;
  }
};
set< pair<ll, ll> , comp> cnt;

int dfs(int node, int dad) {
  vis[node] = 1;
  int sum = 0,f=0;

  for (auto child : adj[node]) {
    if (!vis[child]) f=1,sum += dfs(child, node);
  }
  if (!f) { cnt.insert(mp(w[mp(node, dad)], 1)); tot += w[mp(node, dad)]; return 1; }
  cnt.insert(mp(w[mp(node, dad)], sum));
  tot += w[mp(node, dad)] * sum;
  return sum;
}

void solve(void) {

  ll s;
  tot=0;
  cnt.clear();
  w.clear();

  cin >> n >> s;
  adj.assign(n + 1, vector<int>());
  vis.assign(n + 1, 0);
  rep(i, 0, n - 1) {
    ll u, v, wi;
    cin >> u >> v >> wi;
    w[mp(u, v)] = w[mp(v, u)] = wi;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int l=dfs(1,0);
  // for(auto it: cnt) cerr<<it.first<<" "<<it.second<<endl;
  int ans = 0;
  while (tot > s ) {
    auto temp=*cnt.begin();
    tot-=temp.first*temp.second;
    temp.first/=2;
    tot+=temp.first*temp.second;
    cnt.erase(cnt.begin());
    cnt.insert(temp);
    ans++;
  }
  cout<<ans<<endl;
}

int main()
{
  //Skipped in presense of online judge.
#ifndef ONLINE_JUDGE
  freopen("/home/zeddie/Documents/input.txt", "r", stdin);
  freopen("/home/zeddie/Documents/output.txt", "w", stdout);
  freopen("/home/zeddie/Documents/error.txt", "w", stderr);
#endif

  IOS()
  ll t = 1;
  cin >> t;
  while (t--)
    solve();
}