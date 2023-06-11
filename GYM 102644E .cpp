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
ll a[65][65];
int dx[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int dy[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
const ll mod = 4294967296;
void multiply(ll x[65][65], ll y[65][65])
{
    ll res[65][65];
    for0(i,0,65)
    {
        for0(j,0,65)
        {
            res[i][j] = 0;
            for0(l,0,65)
            {
                res[i][j] += x[i][l]%mod*y[l][j]%mod;
                res[i][j] %= mod;
            }
        }
    }
    for0(i,0,65)
    {
        for0(j,0,65)
        {
            x[i][j] = res[i][j];
        }
    }
}
int main()
{
    ll k; cin >> k;
    memset(a,0,sizeof(a));
    ll base[65][65];
    for0(i,0,65)
    {
        for0(j,0,65)
        {
            base[i][j] = 0;
        }
    }
    base[0][0] = 1;
    for0(i,0,65)
    {
        a[i][64] = 1;
    }
    for0(i,0,8)
    {
        for0(j,0,8)
        {
            for0(l,0,8)
            {
                int ni = i + dx[l];
                int nj = j + dy[l];
                if(ni >= 0 and ni < 8 and nj >= 0 and nj < 8 )
                {
                    a[8*i + j][8*ni +  nj] = 1;
                }
            }
        }
    }
    while(k  > 0)
    {
        if(k  & 1)
        {
            k--;
            multiply(base,a);
        }
        multiply(a,a);
        k /= 2;
    }
    ll sum = 0;
    for0(i,0,65)
    {
        for0(j,0,65)
        {
            sum = (sum + base[i][j]) % mod;
        }
    }
    cout << sum % mod;
}