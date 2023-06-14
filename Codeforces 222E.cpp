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

const int mod = 1e9 + 7;
ll n, m, k;
ll a[60][60];
ll res[60][60];
void matrix(ll x[60][60], ll y[60][60])
{
    ll ans[60][60];
    for0(i,0,m)
    {
        for0(j,0,m)
        {
            ans[i][j] = 0;
            for0(l,0,m)
            {
                ans[i][j] += x[i][l] % mod *y[l][j] % mod;
                ans[i][j] %= mod;
            }
        }
    }
    for0(i,0,m)
    {
        for0(j,0,m)
        {
            x[i][j] = ans[i][j];
        }
    }
}
int transfer(char c)
{
    if(c < 'a') c -= 'A' -  26;
    else c -= 'a';
    return c;
}
void input()
{
    cin >> n >> m >> k;
    for0(i,0,m)
    {
        for0(j,0,m)
        {
            a[i][j] = 1;
        }
    }
    while(k --)
    {
        char c1,c2; cin >> c1 >> c2;
        int x = transfer(c1);
        int y = transfer(c2);
        a[x][y] = 0;
    }
    for0(i,0,m)
    {
        res[i][i] = 1;
    }
}
void solve()
{

    n--;
    while(n > 0)
    {
        if(n & 1)
        {
            n--;
            matrix(res,a);
        }
        matrix(a,a);
        n /= 2;
    }
    ll sum = 0;
    for0(i,0,m)
    {
        for0(j,0,m)
        {
            sum += res[i][j];
            sum %= mod;
        }
    }
    cout << sum % mod << endl;
}
int main()
{
    input();
    solve();
}
