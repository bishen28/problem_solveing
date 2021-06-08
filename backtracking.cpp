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
typedef set<pair<ll,ll>>        spll;
typedef map<ll,ll>              mllll;
typedef map<string,ll>          mstrll;
typedef queue<ll>               qll;



ll powMod(ll x,ll y)            {ll p=1; while(y){if(y%2){p=(p*x)%z;} y/=2; x=(x*x)%z;} return p;}
ll CpowMod(ll x,ll y, ll w)     {ll p=1; while(y){if(y%2){p=(p*x)%w;} y/=2; x=(x*x)%w;}return p;}
ll invMod(ll x)                 {return powMod(x,z-2);}
ll CinvMod(ll x,ll w)           {return CpowMod(x,w-2,w);}
ll gcd(ll a, ll b)              {return b == 0 ? a : gcd(b, a % b);}
 int N,M;
 int  l = 4;
void permutation(string &str, int i, int j){
    
    if(i<l){
        for(int j=i;j<l;j++){
            swap(str[i],str[j]);
            permutation(str,i+1,l);
            swap(str[i],str[j]);
        }
        
    }else{
        cout << str << endl;
        return ;
    }
    
}

void  rat_in_maze(vvll &MTX, int i, int j, string osf){
    if(i<0||j<0||i>=N||j>=M) return;
    if(MTX[i][j]==-2||MTX[i][j]==-1)return;
    if(i==N-1&&j==M-1){
       cout << osf << endl;
       return;
    }
    
    MTX[i][j] = -1;
    rat_in_maze(MTX,i+1,j,osf+"D");
    rat_in_maze(MTX,i-1,j,osf+"U");
    rat_in_maze(MTX,i,j+1,osf+"R");
    rat_in_maze(MTX,i,j-1,osf+"L");
    MTX[i][j] = 0;
}
int n = 8;
void subsetBacktrack(string &str, int i, string &osf){
    if(i<n){
        subsetBacktrack(str,i+1,osf);
        osf = osf+str[i];
        subsetBacktrack(str,i+1,osf);
        if(osf.length()) osf.pop_back();
    }else{
        cout << osf << endl;
        
    }
}




set<int> s;
vpll cell;
int c = 0;
bool check(int r, int c){
    for(auto it:cell){
        if(r - it.F == abs(c-it.S)) return true;
    }
  return false;      
}

int k;

void Nqueen(int i){
    if(s.size()==k){
        c++;
        return;
    }
    
    
    for(int j=0;j<k;j++){
        if(s.find(j)!=s.end()||check(i,j)) continue;
        pair<int,int> p  = {i,j};
        cell.push_back(p);
        s.insert(j);
        Nqueen(i+1); 
        s.erase(j);
        cell.pop_back();
    }
    
    
    
}



int x = 0;
void knightTour(vvll &MTX, ll i, ll j, ll n){
    if(i<0||j<0||i>=n||j>=n) return;
    if(MTX[i][j])return;
    
        MTX[i][j]=++c;
        
        if(c==n*n){
            x++;
        //     for(int i=0;i<n;i++){
        //       for(int j=0;j<n;j++){
        //         cout << MTX[i][j] << " ";
        //       }cout << endl;
        //     }
        //  cout << endl;
        //return;
        }
        knightTour(MTX,i+1,j+1+1,n);
        knightTour(MTX,i+1+1,j+1,n);
        knightTour(MTX,i-1,j-1-1,n);
        knightTour(MTX,i-1-1,j-1,n);
        knightTour(MTX,i+1+1,j-1,n);
        knightTour(MTX,i+1,j-1-1,n);
        knightTour(MTX,i-1,j+1+1,n);
        knightTour(MTX,i-1-1,j+1,n);
        
        MTX[i][j] = 0;
        c--;    
        
}


bitset<10> clm,ld,rd;
void NqueenBitMask(int n){

}






int main(){ 
    
 int N;cin>>N;
    vvll MTX(N,vll(N));
    
    //  for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout << MTX[i][j] << " ";
    //     }cout << endl;
    // }
    // cout << endl;
    knightTour(MTX,0,0,N);
    
    cout << x << endl;
    
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout << MTX[i][j] << " ";
    //     }cout << endl;
    // }
   


return 0; 

}
