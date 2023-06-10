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
#define INF 10000000

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
ll a[101][101];
ll ans[101][101];
ll n;
const int mod = 1000000007;
void matrix(ll x[101][101],ll  y[101][101])
{
    ll c[n][n];
    for0(i,0,n)
    {
        for0(j,0,n)
        {
            c[i][j] = 0;
            for0(l,0,n)
            {
                c[i][j] += x[i][l]%mod*y[l][j]%mod;
                c[i][j] %= mod;
            }
        }
    }
    for0(i,0,n)
    {
        for0(j,0,n)
        {
            x[i][j] = c[i][j];
        }
    }
}
int main()
{
    int m, k; cin >> n >> m >> k;
    memset(a,0,sizeof(a));
    while(m --)
    {
        int x, y; cin  >> x >> y;
        a[x-1][y-1] = 1;
    }
    for0(i,0,n)
    {
        for0(j,0,n)
        {
           ans[i][j] = a[i][j];
        }
    }
    ll x = k  - 1;
    while(x > 0)
    {
        if(x % 2 != 0)
        {
            x--;
            matrix(ans,a);
        }
        matrix(a,a);
        x /= 2;
    }
    ll res = 0;
    for0(i,0,n)
    {
        for0(j,0,n)
        {
            res += ans[i][j];
        }
    }
    cout << res % mod;
}