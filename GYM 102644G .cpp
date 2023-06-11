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

const int mod = 1000000000 + 7;
const int msize = 2e5;
ll n, k;
ll a[13][13], base[13][1], res[13][13];
void matrix(ll x[13][13], ll y[13][13])
{
    ll ans[13][13];
    for0(i,0,n + 3)
    {
        for0(j,0,n + 3)
        {
            ans[i][j] = 0;
            for0(l, 0 ,n + 3)
            {
                ans[i][j] += x[i][l] % mod*y[l][j] % mod;
                ans[i][j] %= mod;
            }

        }
    }
    for0(i,0,n + 3)
    {
        for0(j,0,n + 3)
        {
            x[i][j] = ans[i][j];
        }
    }
}
void matrix1(ll x[13][1], ll y[13][13])
{
    ll ans[13][1];
    for0(i,0,n + 3)
    {
        for0(j,0,1)
        {
            ans[i][j] = 0;
            for0(l, 0 ,n + 3)
            {
                ans[i][j] += x[l][j]% mod*y[i][l] % mod;
                ans[i][j] %= mod;
            }

        }
    }
    for0(i,0,n + 3)
    {
        for0(j,0,1)
        {
            x[i][j] = ans[i][j];
        }
    }
}
ll x[13], y[13];
ll p,q,r;
void input()
{
    cin >> n >> k;
    for0(i,0,n) cin >> x[i];
    for0(i,0,n) cin >> y[i];
    cin >> p >> q >> r;
}
void solve()
{
    for0(i,0,n)   base[i][0] = x[i];
    base[n][0] = 1;
    base[n + 1][0] = n;
    base[n + 2][0] = n*n;
    if(k < n) cout << x[k];
    else
    {
        for0(i,0,n)
        {
            a[n - 1][i] = y[n - i - 1];
            if(i >= 1) a[i - 1][i] = 1;
        }
        a[n - 1][n] = p, a[n - 1][n + 1] = q, a[n - 1][n + 2] = r;
        a[n][n] = 1;
        a[n + 1][n] = 1, a[n + 1][n + 1] = 1;
        a[n + 2][n] = 1, a[n + 2][n + 1] =2, a[n + 2][n + 2] = 1;
        for0(i,0, n + 3)
        {
            for0(j , 0 ,n  + 3)
            {
                if(i == j) res[i][j] = 1;
            }
        }
        ll t = k - n + 1;
        for0(i,0,n  + 3)
        while(t > 0)
        {
            if(t & 1)
            {
                t--;
                matrix(res,a);
            }
            t /= 2;
            matrix(a,a);

        }
        matrix1(base,res);
        cout << base[n - 1][0] % mod<< endl;
    }
}
int main()
{
    input();
    solve();
}