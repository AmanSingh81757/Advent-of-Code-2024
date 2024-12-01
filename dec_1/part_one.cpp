#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p;
typedef vector<ll> v;
typedef vector<string> vs;
typedef vector<p> vp;
typedef map<ll, ll> m;
typedef unordered_map<ll, ll> um;
typedef vector<vector<ll>> vv;
ll MOD = 1e9 + 7;
double eps = 1e-12;
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define int ll
#define fr(i, s, e) for (ll i = s; i < e; i++)
#define fra(a) for (auto it : a)
#define frat(a) for (auto &it : a)
#define rfr(i, s, e) for (ll i = s; i >= e; i--)
#define me max_element
#define mie min_element
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define f first
#define ub upper_bound
#define lb lower_bound
#define INF LLONG_MAX
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void dbg(int a)
{
    cout << a << endl;
}

void dbg(v &a)
{
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}

void dbg(vp &a)
{
    for (auto it : a)
    {
        cout << it.first << " " << it.second << endl;
    }
}

ll power(ll base, ll exp, int mod)
{
    int res = 1;
    if (mod > 1)
        base %= mod;

    while (exp != 0)
    {

        if (exp & 1 == 1)
        {
            res = ((res) * (base));
            if (mod > 1)
                res %= mod;
            exp--;
        }
        else
        {
            base = ((base) * (base));
            if (mod > 1)
                base %= mod;
            exp /= 2;
        }
    }
    return (res);
}
string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string ans = "";
    for (int i = 30; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            ans += '1';
        else
            ans += '0';
    }
    return ans;
}
vector<int> Primes(10000001, 1);
vector<int> primes;
void SieveOfEratosthenes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (Primes[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                Primes[j] = 0;
        }
    }
}

int par[10001];
int rnk[10001];
bool vis[10001];

void initialise()
{
    for (int i = 0; i <= 1000; i++)
    {
        par[i] = i;
        rnk[i] = 1;
        vis[i] = false;
    }
}

int findPar(int node)
{
    if (par[node] == node)
        return node;
    return par[node] = findPar(par[node]);
}

void makeUnion(int a, int b)
{
    int parA = findPar(a);
    int parB = findPar(b);

    if (parA == parB)
        return;
    if (rnk[parA] < rnk[parB])
        par[parB] = parA;
    else if (rnk[parB] < rnk[parA])
        par[parA] = parB;
    else
    {
        rnk[parA]++;
        par[parB] = parA;
    }
}

static bool used[200000 + 1] = {0};

int mex(vector<int> &A)
{

    for (int x : A)
    {
        if (x <= 200000)
            used[x] = true;
    }

    int result = 0;
    int f = 1;
    while (used[result])
    {
        ++result;
    }

    for (int &x : A)
    {
        if (x <= 200000)
            used[x] = false;
    }

    return result;
}

void printCaseNumber(int i)
{
    cout << "Case #" << i << ": ";
}

int check(string s, int ind)
{
    if (ind + 3 < s.size() && s.substr(ind, 4) == "1100")
    {
        return ind;
    }
    if (ind + 2 < s.size() && ind - 1 >= 0 && s.substr(ind - 1, 4) == "1100")
    {
        return ind - 1;
    }
    if (ind + 1 < s.size() && ind - 2 >= 0 && s.substr(ind - 2, 4) == "1100")
    {
        return ind - 2;
    }
    if (ind < s.size() && ind - 3 >= 0 && s.substr(ind - 3, 4) == "1100")
    {
        return ind - 3;
    }
    return -1;
}

int func1(vector<vector<int>> &grid, int &r, int &c, int &n, int &minn, int &maxx)
{
    int left = minn, right = maxx;
    int ans = minn - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (grid[mid][r] < c)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int func2(vector<vector<int>> &grid, int &r, int &c, int &n, int &minn, int &maxx)
{
    int left = minn, right = maxx;
    int ans = maxx + 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (grid[mid][r] > c)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int findXOR(int n)
{
    int mod = n % 4;

    // If n is a multiple of 4
    if (mod == 0)
        return n;

    // If n % 4 gives remainder 1
    else if (mod == 1)
        return 1;

    // If n % 4 gives remainder 2
    else if (mod == 2)
        return n + 1;

    // If n % 4 gives remainder 3
    else
        return 0;
}

int binaryToDecimal(string n)
{
    int decimal = 0;
    for (char c : n)
    {
        decimal = decimal * 2 + (c - '0');
    }
    return decimal;
}

int func(vector<int> &a, vector<int> &b, int ind, int maxx1, int maxx2, vector<vector<int>> &dp)
{

    int copy_maxx1 = maxx1, copy_maxx2 = maxx2;
    int n = a.size();

    if (ind == n) {
        cout << "hi\n";
        return 0;
    }

    // if(dp[maxx1+maxx2][ind] != -1){
    //     return dp[maxx1+maxx2][ind];
    // }

    int ans_a = 0, ans_b = 0;
    if (a[ind] <= maxx1 + maxx2) {
        ans_a++;
    }
    if (a[ind] >= maxx1) {
        maxx2 = maxx1;
        maxx1 = a[ind];
    }
    else if (a[ind] >= maxx2) {
        maxx2 = a[ind];
    }
    ans_a += func(a, b, ind + 1, maxx1, maxx2, dp);


    if(a[ind] != b[ind])
    {
        maxx1 = copy_maxx1, maxx2 = copy_maxx2;
        if (b[ind] <= maxx1 + maxx2) {
            ans_b++;
        }
        if (b[ind] >= maxx1) {
            maxx2 = maxx1;
            maxx1 = b[ind];
        }
        else if (b[ind] >= maxx2) {
            maxx2 = b[ind];
        }
        ans_b += func(a, b, ind + 1, maxx1, maxx2, dp);
    }

    return max(ans_a, ans_b);
}

void solve(int testcase)
{

    vector<int> a(1000), b(1000);
    for(int i=0;i<1000;i++){
        cin >> a[i];
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i=0;i<1000;i++){
        ans += abs(a[i] - b[i]);
    }
    cout << ans << endl;
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // SieveOfEratosthenes(10000001);
    // for(int i=2;i<10000001;i++){
    //     // cout<<Primes[i]<<" ";
    //     if(Primes[i]){
    //         primes.pb(i);
    //     }
    // }
    // vector<int> cnt(10000001, 0);
    // cnt[5] = 2;
    // cnt[6] = 2;
    // for (int i = 7; i < 10000001; i++)
    // {
    //     if (Primes[i] and Primes[i - 2])
    //     {
    //         cnt[i] = cnt[i - 1] + 1;
    //     }
    //     else
    //     {
    //         cnt[i] = cnt[i - 1];
    //     }
    // }

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}
