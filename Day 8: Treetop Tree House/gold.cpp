//////////////////////////////////////////////////////////////////
/////                                                           //
////  Credits: Rahul Verma (CC @vrintle, CF @BlindingKnight)   ///
///  Institution: Delhi Technological University (aka. DCE)   ////
//                                                           /////
//////////////////////////////////////////////////////////////////

#include <chrono>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

template <typename T> using pbds = tree<T, null_type,
	less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
// order_of_key (K): Returns the number of items that are strictly smaller than K

/*

                ~ You don't know the power of the dark side! ~

..-..,'".-     BM\dF. jM@'    !MMM.&^'jjjM#*..`.              !*m.F.    `.....
-`.'^-".^.   ._'-".   ``       `"#.# .]MF.      _.  __-gg..      jMg.   ......
'......._   j#M' jMf       jg_jm..-`  .Mf_ ja   "`  .`  `^" ,_ 4g."@!.  ...,.,
',3&^jCgf ._`"`"'.         .` """!.   .`^^       .....        .""LTgJf.  =/<.,
_@#MMQK##-@"^                         ..                         .'QK_. .!$AGz
MM&&#0$#yF.                          !-M.    .gmMM@!               ."q. ..K#MD
ZM#ZM#$.                             q4M.    ..__,,yg_.              ^\. ..M0#
A0NWM@.                    jggp.    .,m*      .#MMMMM#'..              '  ."M0
BMM$@"                     !MM#'..   -*'      ."QMMMM#`..                 ..^$
BMMM'                      .^@#.'`   _     ,yy___````.                     . `
MMMP                        ...  j.  1.L   .""9*qwwwJ,.                     ..
@@@.                   .     ...P`,  .F`            .`.                     ..
0T`                   .P. . F`      :"~~-  ._.e.,wyyw..,,....
yg.                             '  _g0M0g. .-'`'^`Q$_
Mf                                .jMMMMML    .`-"0M#
@.                              . ."MMMM@^        ."".
f                              .    -.            ...
.                             .                 ._  ...
                            .           .        .    ..
                       ..  -'          .,              ..,   ..,.
                        `.          . ..*. . _     ,   .p_ .-,'jb.
_                     jgg, -'-+..--!.!!!` !' .~.      _0MM/.-.-/@.   .yyygggMM
M0gyy__________.      ^0M'                            "MM^  ...".     `^MMMMMM
MMMMMMMMMMMMMM'.                                                   ..        .

*/

#define F first
#define S second
#define db double
#define ld long db
#define M 1000000007
#define pb push_back
#define ll long long
#define lll __int128
#define vl vector<ll>
#define vd vector<db>
#define vld vector<ld>
#define vvl vector<vl>
#define pl pair<ll,ll>
#define pd pair<db,db>
#define vpl vector<pl>
#define vpd vector<pd>
#define lld __float128
#define ull unsigned ll
#define sz(a) ((ll) a.size())
#define PI 3.141592653589793238
#define all(v) v.begin(), v.end()
#define each(seq) for(auto e: seq)
#define inf numeric_limits<ll>::max()
#define acc(a) accumulate(all(a), 0ll)
#define shuff(a) random_shuffle(all(a))
#define F0(n, i) for(ll i = 0; i < n; i++)
#define F1(n, i) for(ll i = 1; i <= n; i++)
#define google cout << "Case #" << i << ": ";
#define dbgpr(pr) cout << ' ' << #pr << " {" << pr.F << ',' << pr.S << "} "
#define dbgprs(seq) cout << #seq << " <"; each(seq) { dbgpr(e); } cout << ">\n"
#define dbgarr(seq) cout << #seq << " < "; each(seq) { cout << e << ' '; } cout << ">\n"
#define dbgmtx(mat) cout << #mat << " {\n"; each(mat) { cout << ' '; dbgarr(e); } cout << "}\n"
#define lrot(a, l, r, k) rotate(a.begin() + l, a.begin() + l + (k % (r - l + 1)), a.begin() + r + 1)
#define rrot(a, l, r, k) rotate(a.begin() + l, a.begin() + r + 1 - (k % (r - l + 1)), a.begin() + r + 1)
#define dbgmap(hash) cout << #hash << " { "; each(hash) { cout << e.first << ':' << e.second << ' '; } cout << "}\n"
#define dbgtree(tree) cout << #tree << " {\n"; each(tree) { cout << e.first << ": "; dbgarr(e.second); } cout << "}\n"

// Debug Template, copied from Mikel_Arteta_8 (https://codeforces.com/blog/entry/68809)
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef VRINTLE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// End of debugging template

/* ostream& operator<<(ostream& o, const __int128& x) {
    if (x == numeric_limits<__int128>::min()) return o << "-170141183460469231731687303715884105728";
    if (x < 0) return o << "-" << -x;
    if (x < 10) return o << (char)(x + '0');
    return o << x / 10 << (char)(x % 10 + '0');
} */

ll sieve_size = 0, facto_size = 0;
vector<ll> F(facto_size+1);
vector<bool> state(sieve_size+1, 1);
// exp() for (N^K)%M is only valid, when N%M != 0, else return 0
ll exp(ll n,ll k,ll m=M){ll r=1,a=n%m;do{r=k&1?r*a%m:r;a=a*a%m;}while(k/=2);return r;}
ll imod(ll a,ll m=M){return exp(a,m-2,m)%m;}
ll C(ll n,ll r,ll m=M){return r?(F[n]*imod(F[r],m)%m*imod(F[n-r],m)%m)%m:1;}
void facto(ll n=facto_size,ll m=M){F[0]=1;F1(n,i)F[i]=(F[i-1]*i)%m;}
void sieve(ll n=sieve_size){for(ll i=4;i<=n;i+=2)state[i]=0;for(ll i=3;i<=n;i+=2)for(ll j=i*i;j<=n;j+=i)state[j]=0;}
// when floor(-1 / 4) = -1, use this one
template<class T>T fdivf(T a,T b){return a/b-((a^b)<0&&a%b);}

void solve() {
	vector<string> a;
	while(1) {
		string s = ".";
		cin >> s;
		if(s == ".") break;
		a.pb(s);
	}
	debug(a);
	ll n = sz(a), m = sz(a[0]);
	vvl score(n, vl(m, 1));
	F0(n, i) {
		stack<pl> s1; // left to right
		s1.push({inf, 0});
		for(ll j = 1; j + 1 < m; j++) {
			while(s1.top().F < a[i][j]) s1.pop();
			score[i][j] *= j - s1.top().S;
			s1.push({a[i][j], j});
		}
		stack<pl> s2; // left to right
		s2.push({inf, m - 1});
		for(ll j = m - 2; j; j--) {
			while(s2.top().F < a[i][j]) s2.pop();
			score[i][j] *= s2.top().S - j;
			s2.push({a[i][j], j});
		}
	}
	F0(m, j) {
		stack<pl> s1; // left to right
		s1.push({inf, 0});
		for(ll i = 1; i + 1 < n; i++) {
			while(s1.top().F < a[i][j]) s1.pop();
			score[i][j] *= i - s1.top().S;
			s1.push({a[i][j], i});
		}
		stack<pl> s2; // left to right
		s2.push({inf, n - 1});
		for(ll i = n - 2; i; i--) {
			while(s2.top().F < a[i][j]) s2.pop();
			score[i][j] *= s2.top().S - i;
			s2.push({a[i][j], i});
		}
	}
	ll ans = 0;
	F0(n, i) {
		F0(m, j) {
			ans = max(ans, score[i][j]);
		}
	}
	cout << ans;
}

int32_t main() {
	auto start = high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;
	// cin >> t;
	F1(t, i) {
		// google
		solve();
		cout << '\n';
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	debug(duration.count(), " µs!");
	return 0;
}
