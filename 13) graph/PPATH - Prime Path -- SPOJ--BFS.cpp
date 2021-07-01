#include <bits/stdc++.h>
using namespace std;

#define F                       first
#define S                       second
#define f(i,n)                  for(ll i=0;i<=n;i++)
#define rf(i,n)                 for(ll i=n;i>=0;i--)
#define Cf(i,a,b)               for(ll i=a;i<=b;i++)
#define Crf(i,b,a)              for(ll i=b;i>=a;i--)
#define endl                    '\n'           
#define pb                      push_back
#define mp                      make_pair
#define z                       ((ll)1e9 + 7)  
#define every(it,x)             for(auto &it:x)
#define SET(it,x)               for(auto &it:x){cin>>it;}
#define ins                     insert
#define INF                     ((ll)1e18)
#define Test                    ll T; cin>>T; while(T--)
#define all(v)                  v.begin(),v.end()
#define nline                   cout<<endl
#define SZ(v)                   (ll)v.size()
#define pll                     pair<ll,ll>  

//Data types
typedef long long               ll;
typedef vector<ll>              vll;
typedef vector<string>          vstr;
typedef vector<char>            vchar;
typedef vector<pair<ll,ll> >    vpll;
typedef set<ll>                 sll;
typedef set<string>             sstr;
typedef set<pair<ll,ll> >       spll;
typedef map<ll,ll>              mllll;
typedef map<string,ll>          mstrll;
typedef queue<ll>               qll;
//Functions
ll powMod(ll x,ll y)            {ll p=1; while(y){if(y%2){p=(p*x)%z;} y/=2; x=(x*x)%z;} return p;}
ll CpowMod(ll x,ll y, ll w)     {ll p=1; while(y){if(y%2){p=(p*x)%w;} y/=2; x=(x*x)%w;}return p;}
ll invMod(ll x)                 {return powMod(x,z-2);}
ll CinvMod(ll x,ll w)           {return CpowMod(x,w-2,w);}
ll gcd(ll a, ll b)              {return b == 0 ? a : gcd(b, a % b);}

vector<vector<int>> adj_list; 
int finddiff(string a, string b){
    int count=0;
     for(int i=0;i<4;i++){
        if(a[i]!=b[i]) count++;
     }
     return count;
}



void bfs(int s, vector<bool>&visited, vector<int>&distance){
      visited[s] = true;
      queue<int> q;q.push(s);
      distance[s] = 0;
      while(!q.empty()){
            int node = q.front();q.pop();
            for(auto adj_node:adj_list[node]){
                if(visited[adj_node]==false){
                    visited[adj_node] = true;
                    distance[adj_node] = distance[node] + 1;
                    q.push(adj_node);
                }
            }
      }
}



void solve(){
     vector<bool> visited(9999+1);
     vector<int> distance(9999+1);
     int a,b;cin>>a>>b;
     bfs(a,visited,distance);
     if(visited[b]){
        cout << distance[b];
     }else{
        cout << "Impossible";
     }
}

int main(){
int n = 10000;
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
vector<int> prime;
for(int i=1000;i<=9999;i++){
    if(is_prime[i]) prime.push_back(i);
}

int N = prime.size();
adj_list.resize(9999+1); 
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        if(finddiff(to_string(prime[i]),to_string(prime[j]))==1){
            adj_list[prime[i]].push_back(prime[j]);
        }
    }
}
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif 
    int T=1;cin>>T;
    while(T--){
        solve();
        if(T)cout << endl;
    }
    
    return 0;
}
