#include<bits/stdc++.h>
#define FF ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(value, size) cout << bitset<size>(value) << '\n'
#define Tp template<class T>
#define Tpp template<typename T>
#define Tppp template<typename T1,typename T2>
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define all(v) (v).begin(),(v).end()
#define asort(a) sort(a.begin(),a.end())
#define arev(a) reverse(a.begin(),a.end())
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sq(a) ((a)*(a))
#define Ceil(n) (long long int)ceil(n)
#define Floor(n) (long long int)floor(n)
#define deb(a) cout<<#a<<"="<<a<<endl
#define deb2(a,b) cout<<#a<<" , "<<#b<<" = "<<a<<" , "<<b<<endl;
#define deb3(a,b,c) cout<<#a<<" , "<<#b<<" , "<<#c<<" = "<<a<<" , "<<b<<" , "<<c<<endl;
#define deb4(a,b,c,d) cout<<#a<<" , "<<#b<<" , "<<#c<<" , "<<#d<<" = "<<a<<" , "<<b<<" , "<<c<<" , "<<d<<endl;
#define db(x) cout<<#x<<"=  ";for(auto xx:x) cout<<xx<<" ";cout<<endl
#define db2(x) cout<<#x<<"="; for(auto xx:x) cout<<"("<<xx.F<<","<<xx.S<<")"<<" ";cout<<endl
#define d1d(x) for(auto xx:x) cout<<xx<<" ";cout<<endl
using namespace std;

typedef long long int ll;
typedef long double llf;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;


//const int dx[]={1,0,-1,0};const int dy[]={0,1,0,-1}; //4 direction
//const int dx[] = {1, -1, 0, 0, -1, -1, 1, 1}; const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};// 8 direction
//const int dx[]={2,1,-1,-2,-2,-1,1,2};const int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//const int dx[]={2,1,-1,-2,-1,1};const int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction






//-------------------
 //return true /false
//found and that value and not found than greater value pos
 //found and greater value pos && not found also greater pos

Tp string toString(T n) { ostringstream ost; ost << n; ost.flush(); return ost.str();}
string intTobinary(int x) { std::string binary = std::bitset<32>(x).to_string(); return binary;}
string lltobinary(ll x)  {std::string binary = std::bitset<64>(x).to_string(); return binary;}
ll toNumber(string s) {stringstream aa(s);ll mm;aa>>mm; return mm;}
ll binaryToDecimal(string n) { string num = n; ll dec_value = 0; ll base = 1; ll len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value;}
ll ctoint(char c){return c-'a'; }
char inttoc(ll c) {return c+'a'; }

//Binary exponentiation (a^p)
ll Binpow(ll a, ll p){ ll ret = 1; while(p>0){ if(p & 1)ret = (1LL * ret * a) ; a = (1LL * a * a) ; p >>= 1LL; } return ret; }
//BigMod
template<typename A, typename P>
ll BigMod(A a, P p, ll mod){ ll ret = 1; while(p){ if(p & 1)ret = ( (ret%mod) * (a%mod)) % mod; a = ( (a%mod) * (a%mod)) % mod; p >>= 1LL; } return ret; }
//Sorting
Tpp   void make_unique(std::vector<T> &v){v.resize(unique(all(v)) - v.begin()); }
Tpp   void make_unique_sorted(std::vector<T> &v){ asort(v); v.resize(unique(all(v)) - v.begin());}

//Math/Number Theory
ll LCM(ll a, ll b){return (a / __gcd(a, b) ) * b;}


//Bit Hacks
int MSB(ll k)  { return ( 63 - __builtin_clzll(k));}    // leftmost set bit
int LSB(ll k)  { return __builtin_ffs(k)-1 ;}    // right most set bit

ll MakeOneBit(ll decimalvalue, int pos)  { return (decimalvalue | (1 << pos));}    //make pos bit of value 1
ll MakeZeroBit(ll decimalvalue, int pos) {return (decimalvalue & ~(1 << pos));}    //make pos of value bit 0
ll FlipBit(ll decimalvalue, int pos)     { return (decimalvalue ^ (1 << pos));}    //flip pos bit of value reverse
bool CheckBit(ll decimalvalue, int pos) { return (decimalvalue & (1 << pos)); }
int Totalset(ll decimalvalue)  {return __builtin_popcountll(decimalvalue); }   //total 1 in value

const ll MOD = 1e9 + 7;
const ll INFF=LLONG_MAX;
const ll INF=(ll)1e18;

ll lps[1000001];

void findLPS(string &s)
{
    ll i,j;
    lps[0]=0;
    for(i=1,j=0;i<s.length();)
    {
        if(s[i]==s[j])
        {
            lps[i]=j+1;
            i++;j++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=0;
                i++;
            }
            else j=lps[j-1];
        }
    }
}

ll c;
void Compare(string &a,string &b)
{
    ll i,j;
    bool f=false;
    ll asz=a.length();
    ll bsz=b.length();

    for(i=0,j=0;i<asz;)
    {
        if(a[i]==b[j])
        {
            i++;j++;
        }
        else
        {
            if(j==0) i++;
            else j=lps[j-1];
        }

        if(j==bsz)
        {
            //i++;
            c++;
            j=lps[j-1];

        }
    }


   // return j;
    //if(!f) return false;
    //return true;
}



int main()
{
     FF;


     ll tc;cin>>tc;
     rep(xx,1,tc+1)
     {
        string s,pat;cin>>s>>pat;
            c=0;
        findLPS(pat);

        Compare(s,pat);
        cout<<"Case "<<xx<<": ";
        cout<<c<<"\n";





     }

     return 0;
}