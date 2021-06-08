#include <bits/stdc++.h>
using namespace std;

//Macro Shorthands
#define F                       first
#define S                       second
#define f(i,n)                  for(ll i=0;i<=n;i++)
#define rf(i,n)                 for(ll i=n;i>=0;i--)
#define Cf(i,a,b)               for(ll i=a;i<=b;i++)
#define Crf(i,b,a)              for(ll i=b;i>=a;i--)
// #define endl                    '\n'           
#define pb                      push_back
#define mp                      make_pair
#define z                       ((ll)1e9 + 7)  
#define every(it,x)             for(auto &it:x)
#define SET(it,x)               for(auto &it:x){cin>>it;}
#define ins                     insert
#define INF						((ll)1e18)
#define Test                    ll T; cin>>T; while(T--)
#define all(v)                  v.begin(),v.end()
#define nline                   cout<<endl
#define SZ(v)                   (ll)v.size()
#define pll                     pair<ll,ll>  
 

typedef long long               ll;
typedef vector<ll>              vll;
typedef vector<vector<ll>>      vvll;
typedef vector<string>          vstr;
typedef vector<char>            vchar;
typedef vector<pair<ll,ll> >    vpll;
typedef set<ll>                 sll;
typedef set<string>             sstr;
typedef set<pair<ll,ll> >       spll;
typedef map<ll,ll>              mllll;
typedef map<string,ll>          mstrll;
typedef queue<ll>               qll;



ll powMod(ll x,ll y)            {ll p=1; while(y){if(y%2){p=(p*x)%z;} y/=2; x=(x*x)%z;} return p;}
ll CpowMod(ll x,ll y, ll w)     {ll p=1; while(y){if(y%2){p=(p*x)%w;} y/=2; x=(x*x)%w;}return p;}
ll invMod(ll x)                 {return powMod(x,z-2);}
ll CinvMod(ll x,ll w)           {return CpowMod(x,w-2,w);}
ll gcd(ll a, ll b)              {return b == 0 ? a : gcd(b, a % b);}
 
 ll x_to_1(ll &x){
    vll dp(x+1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i=4;i<=x;i++){
       ll divby2 = z;
       ll divby3 = z;
       
       if(i%2==0) divby2 = 1 + dp[x/2];
       if(i%3==0) divby3 = 1 + dp[x/3];
       
       dp[i] = 1 + min({dp[x-1],divby2,divby3});
    }
  return  dp[x];
 }

void solve(){
    ll x;cin>>x;
    cout << x_to_1(x);
}




int main(){
    int T;//cin>>T;
     T = 1;
    while(T--){
        solve();
        if(T)cout << endl;
    }

    return 0;
}
