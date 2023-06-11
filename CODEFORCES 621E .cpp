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
ll a[100][100], ans[100][100];
const int mod = 1e9 + 7;
void matrix(ll x[100][100],ll y[100][100])
{
    ll c[100][100];
    for0(i,0,100)
    {
        for0(j,0,100)
        {
            c[i][j] = 0;
            for0(l,0,100)
            {
                c[i][j] += x[i][l] % mod*y[l][j] %  mod;
            }
        }
    }
    for0(i,0,100)
    {
        for0(j,0,100)
            x[i][j] = c[i][j] % mod;
    }
}
int main()
{
    ll n,k,x,y; cin >> n >> k >> x >> y;
    ll input[n];
    for0(i,0,n) cin >> input[i];
    for0(i,0,y)
    {
        for0(j,0,n)
        {
            a[i][(10*i +input[j]) % y] ++;
            ans[i][(10*i + input[j]) % y] ++;
        }
    }
    k --;
    while(k > 0)
    {
        if(k & 1)
        {
            k--;
            matrix(ans,a);
        }
        k /= 2;
        matrix(a,a);
    }
    cout << ans[0][x] % mod;
}