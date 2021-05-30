//============================================================================
// Name        : BetaTesting.cpp
// Author      : Vinayak Singh
// Version     :
// Copyright   : Your copyright notice
// Description : A. Game of Life in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define push_back push_back
#define mkp make_pair
#define resest(a, b) memset(a, b, sizeof(a))
#define vi vector<ll>
#define pii pair<ll, ll>
#define fi first
#define se second
#define mod (1000000000 + 7)
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end()) //removes repeated element;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

bool prime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void online()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int count_digits(int n)
{
    string num = to_string(n);
    return num.size();
}

bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }
    return subset[n][sum];
}

bool isvow(char s)
{
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return true;
    else
        return false;
}

bool isKthBitSet(int n, int k)
{
    if (n & (1 << k))
        return true;
    else
        return false;
}
bool isPerfectSquare(long double x)
{
    if (x >= 0)
    {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
int main()
{
    // online();
    fast_io;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        ll m;
        cin >> n;
        cin >> m;
        string s;
        cin >> s;
        int dp[n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                int fl = 0, fr = 0, cl = 0, cr = 0;
                int l = i - 1, r = i + 1;
                while (l >= 0)
                {
                    if (s[l] == '1')
                    {
                        fl = 1;
                        cl += 1;
                        break;
                    }
                    cl += 1;
                    l--;
                }
                while (r < n)
                {
                    if (s[r] == '1')
                    {
                        fr = 1;
                        cr += 1;
                        break;
                    }
                    cr += 1;
                    r++;
                }
                if (fl == 1 && fr == 1)
                {
                    int ma = min(cl, cr);
                    if (cl != cr)
                    {
                        if (ma <= m)
                        {
                            dp[i] = ma;
                        }
                    }
                }
                else if (fl == 1 && fr == 0)
                {
                    if (cl <= m)
                    {
                        dp[i] = cl;
                    }
                }
                else if (fl == 0 && fr == 1)
                {
                    if (cr <= m)
                    {
                        dp[i] = cr;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (dp[i] != -1)
                {
                    s[i] = '1';
                }
            }
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
