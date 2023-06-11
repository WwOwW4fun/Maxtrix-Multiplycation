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
ll a[2][2] = {{19,7},{6,20}};
const int mod = 1000000007;
ll n;
void multiply(ll a[2][2], ll b[2][2])
{
    ll c[2][2];
    for0(i,0,2)
    {
        for0(j,0,2)
        {
            c[i][j] = 0;
            for0(l,0,2)
            {
                c[i][j] += a[i][l]*b[l][j];
                c[i][j] %= mod;
            }
        }
    }
    for0(i,0,2)
    {
        for0(j,0,2)
        {
            a[i][j] = c[i][j];
        }
    }
}
int main()
{
    cin >> n;
    ll res[2][2] = {{19,7},{6,20}};
    n -= 1;
    while(n > 0)
    {
        if(n % 2 != 0)
        {
            n--;
            multiply(res,a);
        }
        multiply(a,a);
        n /= 2;
    }
    cout << res[0][0] ;
}