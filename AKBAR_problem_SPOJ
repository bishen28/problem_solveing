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

bool BFS(int strt, vector<vector<int>> &adj_list,vector<bool> &visited,vector<int> &Protected, int S){
      Protected[strt]++;
      visited[strt] = true;
      if(Protected[strt]>1) return false;
      queue<pair<int,int>> q;
      pair<int,int> p;
      p = {strt,S}; q.push(p);
      

      while(!q.empty()){
        p = q.front(); q.pop();
        int node = p.first; int S_left = p.second-1;
        
        if (S_left < 0){
            continue;
        }

        for(auto adj_node:adj_list[node]){
               if(visited[adj_node]==false){
                   visited[adj_node] = true;
                   Protected[adj_node]++;
                   q.push({adj_node,S_left});
               }
        }
      }
  return true;
}


void solve(){
 int N,R,M;cin>>N>>R>>M;
 vector<vector<int>> adj_list(N+1);
 vector<int> Strength(N+1,-1);
 vector<bool> visited(N+1,false);
 vector<int> Protected(N+1,0);
 for(int i=0;i<R;i++){
    int A,B;cin>>A>>B;
    adj_list[A].push_back(B);
    adj_list[B].push_back(A);
 }
     
 for(int i=0;i<M;i++){
    int K,S;cin>>K>>S;
    Strength[K] = S;
 }

bool flag=true;
for(int i=1;i<=N;i++){
   // cout << i << " " << Strength[i] << endl;
    if(Strength[i]>=0){
       flag =   BFS(i,adj_list,visited,Protected,Strength[i]);
       if(!flag) break;
    }
}

if(!flag){
    cout << "No";
    return;
}else{
    for(int i=1;i<=N;i++){
        if(visited[i]==false){
            flag = false;
            break;
        }
    }
}
 if(flag)cout << "Yes"; 
 else cout << "No";


 
 
 
}

int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    int T=1;cin>>T;
    while(T--){
        solve();
        if(T)cout << endl;
    }
    
    return 0;
}
