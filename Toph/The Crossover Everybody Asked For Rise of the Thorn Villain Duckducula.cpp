/*
	problem link: https://toph.co/p/the-crossover-everybody-asked-for-rise-of-the-thorn-villain-duckducula
	Author : SajidAbdullah

*/

#include<bits/stdc++.h>
#define FF ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(value, size) cout << bitset<size>(value) << '\n'
#define Tp template<class T>
#define Tpp template<typename T>
#define eps 1e-67
#define pf printf
#define sf scanf
#define clr(arr) memset((arr),0,(sizeof(arr)))
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
#define mt make_tuple
#define BS(v,x) binary_search(v.begin(),v.end(),x) //return true /false
#define LB(v,x) lower_bound(v.begin(),v.end(),x)//found and that value and not found than greater value pos
#define UB(v,x) upper_bound(v.begin(),v.end(),x) //found and greater value pos && not found also greater pos
#define sma(c) towlower(c)
#define rt(x) sqrt(x)
#define cap(c) towupper(c)
#define sq(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define mx 10000001
#define MX 100000
#define SZ(x) long long int(x.size())
#define Ceil(n) (long long int)ceil(n)
#define Floor(n) (long long int)floor(n)
#define deb(x) std::cout << #x << " = " << x << std::endl;
#define out(ans) cout<<ans<<endl
#define outs(ans) cout<<ans<<" "<<endl
#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

typedef string str;
typedef long long int ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef char ch;
typedef map<ll,ll> mpl;
typedef priority_queue<int> heap;
typedef priority_queue<int, vector<int>, greater<int> > revheap;

//vector<vector<int>> grid(n, vector<int>(n, 0)); // 2D Array inititalize with 0 n*n size

bool isLetter(char c) { return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z');}
bool isUpperCase(char c) {return c >= 'A' and c <= 'Z';}
bool isLowerCase(char c) {    return c >= 'a' and c <= 'z';}
bool isDigit(char c) {return c >= '0' and c <= '9';}
bool isVowel(char c) {return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';}
bool isConsonant(char c){    return !isVowel(c); }

Tp void Debug(T v) { for(int i=0; i<(int)v.size(); i++)  cout << v[i] <<" ";   cout<<endl;  }

Tp void Input(T &v){ for(int i=0; i<(int)v.size(); i++) cin >> v[i]; }

Tp string toString(T n) { ostringstream ost; ost << n; ost.flush(); return ost.str();}

string intTobinary(int x) { std::string binary = std::bitset<32>(x).to_string(); return binary;}
string lltobinary(ll x)  {std::string binary = std::bitset<64>(x).to_string(); return binary;}
ll toNumber(string s) {stringstream aa(s);ll mm;aa>>mm; return mm;}
ll binaryToDecimal(string n) { string num = n; ll dec_value = 0; ll base = 1; ll len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value;}

//nCr

Tpp T nCr(T n, T r) { if(r > n - r) r = n - r; int  ans = 1,i;for(i = 1; i <= r; i++) { ans *= n - r + i; ans /= i; }  return ans; }

//Binary exponentiation
ll Binpow(ll a, ll p){ ll ret = 1; while(p>0){ if(p & 1)ret = (1LL * ret * a) ; a = (1LL * a * a) ; p >>= 1LL; } return ret; }

//BigMod (a^p)%mod
template<typename A, typename P>
int BigMod(A a, P p, int mod){ int ret = 1; while(p){ if(p & 1)ret = (1LL * ret * a) % mod; a = (1LL * a * a) % mod; p >>= 1LL; } return ret; }

//Base (value,base)
Tpp T toBase(T n, T base){T ret= 0LL; while(n){ ret += n % base; ret *= 10LL;  n /= base;} return ret;}

// Divisor

Tpp  vector<T> Divisor(T value){ vector<T> v; for(int i = 1LL; i * i <= value; ++i){
    if(value % i == 0){v.push_back(i); if(i * i != value) v.push_back(value / i);} } return v;}

//Primes

Tpp  bool prime(T n){if (n % 2 == 0) return 0;for (T i = 3; i*i <= n; i += 2){if (n % i == 0) return 0;}return 1;}

//Sieve
Tpp  void Sieve(T n){bool prime[n+1];memset(prime, true, sizeof(prime));
     for (T p=2; p*p<=n; p++){ if (prime[p] == true){
            for (int i=p*p; i<=n; i += p) prime[i] = false;} } }
//Math

Tpp   ll sum(std::vector<T> &v){ return std::accumulate(all(v), 0); }
Tpp   T minval(std::vector<T> &v){ return *std::min_element(all(v));}
Tpp   T maxval(std::vector<T> &v){ return *std::max_element(all(v));}
Tpp   void make_unique(std::vector<T> &v){v.resize(unique(all(v)) - v.begin()); }
Tpp   void make_unique_sorted(std::vector<T> &v){ asort(v); v.resize(unique(all(v)) - v.begin());}
Tpp   int lowerBound(std::vector<T> &v, T x){return v.back() < x ? -1 : lower_bound(all(v), x) - v.begin();}
Tpp   int upperBound(std::vector<T> &v, T x){return v.back() < x ? -1 : upper_bound(all(v), x) - v.begin();}

double startTime = clock();
void showCurrentTime(){ printf("%.6lf\n", ((double)clock() - startTime) / CLOCKS_PER_SEC);}



//Bit Hacks
ll MakeOneBit(ll decimalvalue, int pos)  { return (decimalvalue | (1 << pos));}    //make pos bit of value 1
ll MakeZeroBit(ll decimalvalue, int pos) {return (decimalvalue & ~(1 << pos));}    //make pos of value bit 0
ll FlipBit(ll decimalvalue, int pos)     { return (decimalvalue ^ (1 << pos));}    //flip pos bit of value reverse
bool CheckBit(ll decimalvalue, int pos) { return (decimalvalue & (1 << pos)); }
int MSB(ll k)  { return ( 63 - __builtin_clzll(k));}    // leftmost set bit
int LSB(ll k)  { return __builtin_ffs(k)-1 ;}    // right most set bit
int Totalset(ll decimalvalue)  {return __builtin_popcountll(decimalvalue); }   //total 1 in value

int Totolnotset(ll decimalvalue) { return MSB(decimalvalue) - Totalset(decimalvalue) + 1;}    //total 0 in value

bool ispow2(int i) { return i&&(i&-i)==i; }

ll nC2(ll n) { return (n * (n - 1)) / 2;}
ll nc3(ll n){ return (n * (n - 1) * (n - 2)) / 6; }
ll arithsum(ll n, ll a = 1, ll d = 1){ return (n * (a + a + (n - 1) * d) ) / 2; }
ll LCM(ll a, ll b){return (a / __gcd(a, b) ) * b;}
ll OnetoNsum(ll n){return (n*(n+1))/2;}
ll longdivision(string s,ll a){ ll ans=0; ll temp=0; rep(i,0,s.length()){ temp=temp*10+(s[i]-'0');ans+=(temp/a);ans*=10;temp=temp%a;}return (ans/10);}


const long long int INF=1000000000000000000;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double PIby2=asin(1.0);
const int MOD = 1e9 + 7;

//debug
Tpp void debugvec(vector<T> v){for(ll i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;}
void debugF(vpll v){for(ll i=0;i<v.size();i++){cout<<v[i].F<<"  ";}cout<<endl;}
void debugS(vpll v){for(ll i=0;i<v.size();i++){cout<<v[i].S<<"  ";}cout<<endl;}
void outdeb(string s){cout<<s<<endl;}
void debvel(vll v,ll pos){ cout<<pos<<"="<<v[pos]<<endl;}
//for debugging debfun1,fun2 etc

//const int dx[]={1,0,-1,0};const int dy[]={0,1,0,-1}; //4 direction
//const int dx[] = {1, -1, 0, 0, -1, -1, 1, 1}; const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};// 8 direction
//const int dx[]={2,1,-1,-2,-2,-1,1,2};const int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//const int dx[]={2,1,-1,-2,-1,1};const int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

//-------------------------------------------------------------------------------------------------------------------

//cout<<fixed<<setprecision(decimal)<<value<<endl;
//vector<vector<int>> grid(n, vector<int>(n, 0)); 2D Array
//s.erase(remove(s.begin(),s.end(),' '),s.end());


bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}


int status[(mx/32)+2];
ll n=mx;
vll primes;
void sieve()
{

	 memset(status,0,sizeof(status));
	 int i, j, sqrtN;
     sqrtN = ll( sqrt( n ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for(j = i*i; j <= n; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }
	 //primes.pb(2);

	 //for(i=3;i<=N;i+=2)
       // if( Check(status[i>>5],i&31)==0) primes.pb(i);

}
void Msg()
{
    cout<<"The Argonaut Shines Upon thy Who is for thy Worthy!!!!:";
}

void realm()
{
    cout<<" Never Realm Empire"<<endl;
}

void other()
{
    cout<<" Thorn Villain Duckducula"<<endl;
}
void draw()
{
    cout<<" Go find Kami Hestia Fast!!"<<endl;
}
int main()
{
     ll tc;cin>>tc;
     sieve();
     while(tc--)
     {
         ll n;cin>>n;
         cin.ignore(256,'\n');
         string s;getline(cin,s);
         stack<char> st;
         ll tot=0;
         ll empire=0,duch=0;
         for(ll i=0;i<s.length();i++)
         {
             if(s[i]=='[')
             {
                 tot++;
                 if(tot%2==1)
                 {
                     empire++;
                 }
             }
             else if(s[i]==']')
             {
                 tot++;
                 if(tot%2==1)
                 {
                     duch++;
                 }
             }
         }
         string quote;getline(cin,quote);

         int qlen=quote.length();
         //deb(qlen);
         ll doublechar=0;
        if(qlen>=2)
        {
            for(int i=qlen; i>=0; i--)
            {
                if( Check(status[i>>5],i&31)==0 && i%2==1)
                {
                    doublechar=i;
                    //deb(doublechar);
                    break;
                }
                else if(i==2)
                {
                    doublechar=i;
                    break;
                }
            }
        }
        
         ll mm=0,nn=0;
         if(empire!=0 && doublechar!=0 ) mm=(doublechar/empire);
         if(duch!=0 && doublechar!=0) nn=(doublechar/duch);
         Msg();
         //deb(empire);deb(empire);
         //deb(doublechar);
         if(mm>nn)
         {
             realm();
         }
         else if(mm==nn)
         {
             draw();
         }
         else other();
     }
     return 0;
}