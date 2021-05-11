//============================================================================
// Name        : BetaTesting.cpp
// Author      : Vinayak Singh
// Version     :
// Copyright   : Your copyright notice
// Description : A. Phoenix and Gold in C++, Ansi-style
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
#define pb push_back
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

int solve(int arr[], ll n, ll count, int index)
{
    if (index < 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        // cout << count << endl;
        return count;
    }
    int include = solve(arr, n - arr[index], count++, index);
    int notInclude = 0;
    if (n - arr[index] > 0)
    {
        notInclude = solve(arr, n, count, index--);
    }
    return max(include, notInclude);
}

int main()
{
    //  online ();
    fast_io;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        ll sum = 0;
        rep(i, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        if ((n == 1 && a[0] == x) || sum == x)
            cout << "NO\n";
        else if (n == 1 && a[0] != x)
        {
            cout << "YES\n";
            cout << a[0];
            cout << "\n";
        }
        else
        {
            sort(a, a + n);

            if (x == a[n - 1])
            {
                cout << "YES" << endl;
                cout << a[n - 2] << " " << a[n - 1] << " ";
                for (int i = n - 3; i >= 0; i--)
                {
                    cout << a[i] << " ";
                }
            }
            else
            {
                int sum = 0;
                int arr[n];
                string s = "YES";
                for (int i = n - 1; i >= 0; i--)
                {
                    if (a[i] < 0)
                    {
                        continue;
                    }
                    else
                    {
                        sum += a[i];
                        if (sum == x)
                        {
                            if (i != 0)
                            {
                                arr[i - 1] = a[i];
                                arr[i] = a[i - 1];
                                a[i - 1] = -1;
                                sum += arr[i - 1] + arr[i];
                            }
                            else
                            {
                                s = "NO";
                            }
                        }
                        else
                        {
                            arr[i] = a[i];
                        }
                    }
                }
                if (s == "NO")
                {
                    cout << s << endl;
                }
                else
                {
                    cout << s << endl;
                    for (int i = n - 1; i >= 0; i--)
                    {
                        cout << arr[i] << " ";
                    }
                }
            }
            cout << "\n";
        }
    }
    return 0;
}