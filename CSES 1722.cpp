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
ll n;
long long a[2][2] = {{0,1},{1,1}};
const int mod = 1000000007;
void multiply(long long a[2][2],long long b[2][2], long long c[2][2])
{
    for(int i = 0; i < 2 ; i++)
    {
        for(int j = 0; j < 2 ; j++)
        {
            c[i][j] = 0;
        }
    }
    for(int i = 0; i < 2 ; i++)
    {
        for(int j = 0; j < 2 ; j++)
        {
            for(int k = 0; k < 2 ; k++)
            {
                c[i][j] += a[i][k]%mod*b[k][j]%mod;
                c[i][j] %= mod;
            }
        }
    }
    for(int  i = 0 ; i < 2 ; i++)
    {
        for(int j = 0; j < 2 ; j++)
        {
            a[i][j] = c[i][j];
        }
    }
}
int main()
{
    cin >> n;
    if(n == 0) cout << 0;
    else
    {
        ll ans[2][2] = {{0,1},{1,1}};
        ll res[1][2];
        ll t[2][2];
        ll x = n - 2;
        while(x > 0)
        {
            if(x % 2 != 0)
            {
                x--;
                multiply(ans,a,t);
            }
            multiply(a,a,t);
             x /= 2;

        }
        int g[2][2] = {0,1};
        memset(res,0,sizeof(res));
        for(int  i = 0; i < 1 ; i++)
        {
            for(int j = 0 ; j < 2 ; j++)
            {
                for(int l = 0; l < 2 ; l++)
                {
                    res[i][j] += g[i][l]*ans[l][j];
                    res[i][j] %= 1000000007;
                }
            }
        }
        cout << res[0][1] % mod;
    }
}