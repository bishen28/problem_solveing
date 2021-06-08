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
 
 
 
 
void solve(){
     string s1,s2,s3;cin>>s1>>s2>>s3;
     int n1 = s1.length();
     int n2 = s2.length();
     int n3 = s3.length();
     
     int dp[n1+1][n2+1][n3+1];
     
     memset(dp,0,sizeof(dp));
     string s;
     for(int i=1;i<=n1;i++){
         for(int j=1;j<=n2;j++){
             for(int k=1;k<=n3;k++){
                 if(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1]){
                     s.push_back(s1[i-1]);
                     dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                 }else{
                 dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]}); 
                 }
             }
         }
     }
     
cout << dp[n1][n2][n3] << " " << s;

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
