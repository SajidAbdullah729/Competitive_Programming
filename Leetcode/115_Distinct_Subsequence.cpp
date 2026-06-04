
/*
    https://leetcode.com/problems/distinct-subsequences/
    Author: SajidAbdullah
*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define FF ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(value, size) cout << bitset<size>(value) << '\n'
#define Tp template<class T>
#define Tpp template<typename T>
#define Tppp template<typename T1,typename T2>
#define eps 1e-9
#define pf printf
#define sf scanf
#define clr(arr,val) memset((arr),val,(sizeof(arr)))
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define repb(i,a,b) for(long long int i=a;i>=b;i--)
#define all(v) (v).begin(),(v).end()
#define asort(a) sort(a.begin(),a.end())
#define arev(a) reverse(a.begin(),a.end())
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define pbb pop_back
#define mp make_pair
#define V vector
#define P pair
#define M map
#define mt make_tuple
#define BS(v,x) binary_search(v.begin(),v.end(),x) //return true /false
#define LB(v,x) lower_bound(v.begin(),v.end(),x)-v.begin()//found and that value and not found than greater value pos
#define UB(v,x) upper_bound(v.begin(),v.end(),x)-v.begin() //found and greater value pos && not found also greater pos
#define sma(c) towlower(c)
#define rt(x) sqrt(x)
#define cap(c) towupper(c)
#define sq(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define SUM(v) accumulate (v.begin(),v.end(),0)//sum of the vector
#define MAX(v) *max_element(v.begin(),v.end())//max element of the vector
#define MIN(v) *min_element(v.begin(),v.end())//min element of the vector
#define SZ(x) long long int(x.size())
#define Ceil(n) (long long int)ceil(n)
#define Floor(n) (long long int)floor(n)
#define deb(x) cout << #x << " = " << x << "\n";
#define deb2(x,y)  cout << #x << " = " << x << ", "; cout << #y << " = " << y << "\n";
#define deb3(x,y,z) cout << #x << " = " << x << ", "; cout << #y << " = " << y << ", "; cout << #z << " = " << z << "\n";
#define deb4(x,y,z,r) cout << #x << " = " << x << ", "; cout << #y << " = " << y << ", "; cout << #z << " = " << z << ", ";cout << #r << " = " << r << "\n";
#define out(ans) cout<<ans<<"\n"
#define outs(ans) cout<<ans<<" "<<"\n"
#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)

using namespace std;
//using namespace __gnu_pbds;

typedef int ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long int ull;
typedef vector<ll> vll;

typedef vector<vector<ll> > v2d;
typedef vector<vector<vector<ll> > > v3d;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef map<ll,ll> mpl;
typedef priority_queue<ll> heap;// heap max value from top
typedef priority_queue<ll, vector<ll>, greater<ll> > revheap;//heap min value from top
typedef vector<char> vcl;
typedef vector<vcl> vcll;

ll fun(ll i,ll j,string &s1,string &s2,ll n,ll m,v2d &dp,vector<vector<bool>> &vis)
{
    if(j==m) return 1;
    if(i==n) return 0;
    if(vis[i][j]) return dp[i][j];
    ll yy=0;
    ll xx=fun(i+1,j,s1,s2,n,m,dp,vis);
    if(s1[i]==s2[j])
    {
        yy=fun(i+1,j+1,s1,s2,n,m,dp,vis);
    }
    //zz=fun(i+1,j,s1,s2,n,m,dp,vis);
    vis[i][j]=1;
    return dp[i][j]=(xx+yy);

}
class Solution {
public:
    int numDistinct(string s, string t) {
        ll n=s.length();
        ll m=t.length();
        v2d dp(n+5,vll(m+5,0));
        vector<vector<bool> > vis(n+5,vector<bool>(m+5,0));
        return fun(0,0,s,t,n,m,dp,vis);
    }
};