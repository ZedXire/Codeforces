//Mark XXII
#include<bits/stdc++.h>

#define big(x) greater<x>()
#define ll long long int
#define M 998244353
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" : "<<x<<"\n";
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,b,c) for(int i=b; i<c; ++i)

using namespace std;

void solve()
{
  int n;
  string a,b;
  cin>>n>>a>>b;
  int ans=0;
  // if(a[0]!=b[0] and (a[1]==b[1] or a[0]==a[1]) ) ans++,a[0]=b[0];
  // if(a[n-1]!=b[n-1] and (a[n-2]==b[n-2] or a[n-1]==a[n-2]) ) ans++,a[n-1]=b[n-1];
  rep(i,1,n-1)
  {
    if(a[i]==b[i]) continue;

    if(a[i-1]!=b[i-1] and a[i-1]!=a[i]) a[i-1]=b[i-1];
    else if(a[i+1]!=b[i+1] and a[i+1]!=a[i]) a[i+1]=b[i+1];
    ans++;
    a[i]=b[i];
  }
  if(n==2 and a[0]!=a[1] and a[0]!=b[0] and a[0]==b[1]) ans++;
  else
  {
    if(a[0]!=b[0]) ans++,a[0]=b[0];
    if(a[n-1]!=b[n-1]) ans++;
  }
  cout<<ans;
}

int main()
{
  //Skipped in presense of online judge.
  #ifndef ONLINE_JUDGE
  freopen("/home/zeddie/Documents/input.txt","r",stdin);
  freopen("/home/zeddie/Documents/output.txt","w",stdout);
  freopen("/home/zeddie/Documents/error.txt","w",stderr);
  #endif

  IOS()
  ll t=1;
  //cin>>t;
  while(t--)
    solve();
}