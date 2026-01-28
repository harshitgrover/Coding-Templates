// Boilerplate code with macros

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbl long double
#define str string
#define elif else if
#define fi(i, a, b) for (ll i = a; i < b; i++)
#define fd(i, a, b) for (ll i = a; i > b; i--)
#define input(a) for (ll _ = 0; _ < a.size(); _++) cin >> a[_]
#define iter(a, b) for (auto & b: a)
#define iterp(a) for (auto & [it1, it2]: a)
#define prinv(a) iter(a, _) {cout << _ << " ";} cout << endl
#define prin(a) cout << a << " "
#define print(a) cout << a << endl
#define prinp(a) {prin(a.first); print(a.second);}
#define nline() cout << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define emb emplace_back
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define fs first
#define sc second
#define idk print("ok")
#define yes print("YES")
#define no print("NO")
#define vll vector<ll>
#define vint vector<int>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define sll set<ll>
#define vbool vector<bool>
#define vset vector<sll>
#define vstr vector<str>
#define vchar vector<char>
#define vpair vector<pair<ll, ll>>
#define vdbl vector < long double >
#define lcm(a,b) (((a)/gcd(a,b))*b)

const ll inf = 1e16;
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;

void solve(ll T) {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << fixed << setprecision(9);
    ll T = 1;
    cin >> T;
    fi(_,1,T+1) {
        solve(_);
    }
    return 0;
}
