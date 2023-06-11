/* 
Author : Nguyen Xuan An 
Gmail : xuanan437@gmail.com
*/   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for1(i, l, r) for(int i = (l); i >= (r); --i)
#define for2(v) for(auto it : v)
#define reset(a) memset(a,0,sizeof(a))
#define mem(a) memset(a,-1,sizeof(a))
#define membo(a) memset(a,false,sizeof(a))

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>
#define pll pair<long long, long long >
#define fi first
#define se second
#define prq priority_queue
#define pb push_back

#define output ios::sync_with_stdio(0);cin.tie(0);
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define PI 3.1415926535897932385
#define INF 2e18

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
const int mod = 1000000000;
ll a[12][12], base[1][12];
ll res[12][12];
ll n, k;
void matrix(ll x[12][12], ll y[12][12])
{
    ll ans[k][k];
    for0(i,0,k)
    {
        for0(j,0,k)
        {
            ans[i][j] = 0;
            for0(l,0,k)
            {
                ans[i][j] += x[i][l] * y[l][j];
                ans[i][j] %= mod;
            }
        }
    }
    for0(i,0,k)
    {
        for0(j,0,k)
        {
            x[i][j] = ans[i][j];
            x[i][j] %= mod;
        }
    }
}
ll b[12],c[12];
void input()
{
    cin >> k;
    for0(i,0,k) cin >> b[i];
    for0(i,0,k) cin >> c[i];
    cin >> n;
    if(n <= k) cout << b[n-1] << endl;
    else
    {
         for0(i,0,k)
        {

            for0(j,0,k)
            {
                if(i != k - 1)
                {
                    a[i][j] = 0;
                }
                else a[i][j] = c[k - j - 1] % mod;
            }
            a[i][i + 1] = 1;
        }
        for0(i,0,k)
        {
            for0(j,0,k)
            {
                res[i][j] = a[i][j];
            }
        }
        ll x = n - k - 1;
        while(x > 0)
        {
            if(x % 2 != 0)
            {
                x--;
                matrix(res,a);
            }
            x /= 2;
            matrix(a,a);
        }
        ll ans[1][k];
        for0(j,0,k)
        {
            ans[0][j] = 0;
            for0(l,0,k)
            {
                ans[0][j] += b[l] % mod*res[j][l] % mod;
                ans[0][j] %= mod;
            }
        }
        cout << ans[0][k - 1] % mod << endl;
    }
}
int main()
{
        int tc; cin >> tc;
        while(tc --)
        {
         input();
        }
}