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

#define M 1000000007
#define LINF 1e18
#define INF INT_MAX
using namespace std;

ll i,j,n,m,k;
double h,c,T;

double dif(ll x)
{
  double temp=((h+c)*x-c)/(2*x-1.0);
  return (T>temp)?T-temp:temp-T;
}
void solve()
{
  cin>>h>>c>>T;
  if(T<=(h+c)/2) { cout<<"2\n"; return; }
  double x=(T-c)/(2*T-h-c);
  int p=floor(x),q=ceil(x);

  if(dif(p)<=dif(q)) cout<<2*p-1<<endl;
  else cout<<2*q-1<<endl;
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
  cin>>t;
  while(t--)
    solve();
} 