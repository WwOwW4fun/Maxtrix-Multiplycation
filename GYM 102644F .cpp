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
ll a[100][100];
ll n;
void multiply(ll d[100][100], ll b[100][100])
{
    ll c[100][100];
    for0(i,0,n)
    {
        for0(j,0,n)
        {
            c[i][j] = INF;
            for0(l,0,n)
            {
                c[i][j] = min(c[i][j],d[i][l]+b[l][j]);
            }
        }
    }
    for0(i,0,n)
    {
        for0(j,0,n)
        {
            d[i][j] = c[i][j];
        }
    }
}
int main()
{
    ll m ,k;
    cin >> n >> m >> k;
    for0(i,0,n)
    {
        for0(j,0,n)
        {
            a[i][j] = INF;
        }
    }

    while(m --)
    {
        int u, v ,w; cin >> u >> v >> w;
        a[u-1][v-1] = w;
    }
    ll res[100][100];
    for0(i,0,n)
    {
        for0(j,0,n)
        {
             res[i][j] = a[i][j];
        }
    }
    k -= 1;
    while( k > 0)
    {
        if(k&1)
        {
            k--;
            multiply(res,a);
        }
        multiply(a,a);
        k /= 2;

    }
    ll sum = INF;
    for0(i,0,n)
    {
        for0(j,0,n)
        {
            sum = min (sum,res[i][j]);
        }
    }
    if(sum > INF / 2) cout << "IMPOSSIBLE";
    else cout << sum;
}