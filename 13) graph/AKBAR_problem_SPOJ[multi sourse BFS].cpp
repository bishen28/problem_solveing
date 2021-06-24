#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;


using ll = long long;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl =  vector<ll>;
using vpi = vector<pi>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpl = vector<pl>;
using vti = vector<ti>;
using vtl = vector<tl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvpi = vector<vpi>;
using vvpil = vector<vpil>;
using vvpli = vector<vpli>;
using vvpl = vector<vpl>;
using vvti = vector<vti>;
using vvtl = vector<vtl>;

using oset =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

using omset =  tree<pair<int,int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const int MOD = 1000000000 + 7;

#define setbits(n) __builtin_popcount(n)

const int N = (int) 1e6;
vi g[N+1];
int visited[N+1];
vpi src;

bool bfs() {    /// here we are applying multi sourse BFS
    queue<pi> q;
    int sz = (int) src.size();

    for (int i = 0; i < sz; i++) {
        q.push({src[i].first, src[i].second});
        visited[src[i].first] = src[i].first;
    }

    while (!q.empty()) {
        int u = q.front().first;
        int strength = q.front().second;
        assert(visited[u]);
        q.pop();
        if (strength <= 0) {
            continue;
        }
        for (int v : g[u]) {
            if (!visited[v]) {
                visited[v] = visited[u];
                q.push({v, strength-1});
            } else {
                if (visited[v] == visited[u]) {
                    continue;
                }
                assert(visited[v] != visited[u]);
                return false;
            }
        }
    }
    return true;
}
void reset(int n) {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        visited[i] = 0;
    }
    src.clear();
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, r, m;
        cin >> n >> r >> m;
        for (int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        for (int i = 0; i < m; i++) {
            int k, s;
            cin >> k >> s;
            src.emplace_back(k, s);
        }

        bool flag = bfs();


        if (!flag) {
            cout << "No\n";
        } else {
            bool ans = true;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        reset(n);
    }
    return 0;
}
