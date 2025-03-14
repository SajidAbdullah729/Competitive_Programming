//problem link: https://toph.co/p/gcd-grid
/*
  Author : SajidAbdullah
*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define FF ios_base::sync_with_stdio(0);cin.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define deb(x) cout<<#x<<"="<<x<<endl
#define sq(a) ((a)*(a))
#define F first
#define S second
#define mp make_pair
#define mx 25001
#define MX 1000001
typedef long long int ll;
typedef long double llf;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}


int status[(mx/32)+2];
ll N=mx;
vll primes;
void sieve()
{

	 memset(status,0,sizeof(status));
	 int i, j, sqrtN;
     sqrtN = ll( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for(j = i*i; j <= N; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }
	 primes.pb(2);

	 for(i=3;i<=N;i+=2)
        if( Check(status[i>>5],i&31)==0) primes.pb(i);

}

ll arr[1010][1010];

int main()
{
    FF;
    sieve();
    ll n,m;cin>>n>>m;
    vll p1,p2;
    for(ll i=0;i<n;i++)
    {
        p1.pb(primes[i]);
    }
    for(ll i=0;i<m;i++)
    {
        p2.pb(primes[n+i]);
    }

    if(n>m)
    {
        sort(p1.begin(),p1.end());
        reverse(p1.begin(),p1.end());
    }
    else
    {
        sort(p2.begin(),p2.end());
        reverse(p2.begin(),p2.end());
    }

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            arr[i][j]=p1[i]*p2[j];
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}