#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define MOD 1000000007
#define N 512
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef int ll;
ll i,j,n,h,x,y,glob,k,m,p,fx,fy;
ll a[505][505], dp[505][505], d[505][505], t[4][2005][2005];
ll dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
vector<pair<ll,ll> > g[250505];
vector<pair<ll, pair<ll,ll> > > lst, bfs;
ll Abs(ll x)
{
	return x>0?x:-x;
}
ll find_dist(ll x1, ll y1, ll x2, ll y2)
{
	return Abs(x1-x2) + Abs(y1-y2);
}
bool in_range(ll x, ll y)
{
	return (x >= 0 && x < y);
}

int get (int lx, int rx, int ly, int ry) {
	rx++;
	ry++;
	int res = MOD;
	ll l = ly, r = ry;
  for (lx += N, rx += N; lx < rx; lx >>= 1, rx >>= 1) {
  	if (rx&1)
  	{
  		ly = l; ry = r;
	    rx--;
	    for (ly += N, ry += N; ly < ry; ly >>= 1, ry >>= 1) {

		    if (ly&1)
		    {
		       res = min(res, t[glob][rx][ly]);
		       ly++;
		    }
			if (ry&1)
			{
			    --ry;
			    res = min(res, t[glob][rx][ry]);
			}
		}
	}
    if (lx&1)
    {
    	ly = l; ry = r;
		for (ly += N, ry += N; ly < ry; ly >>= 1, ry >>= 1) {

		    if (ly&1)
		    {
		       res = min(res, t[glob][lx][ly]);
		       ly++;
		    }
			if (ry&1)
			{
			    --ry;
			    res = min(res, t[glob][lx][ry]);
			}
		}
	    lx++;
    }
  }
  return res;
}

void update (int x, int y, int val) {
	ll tmp = y;
	t[glob][x+N][tmp+N] = val;
	for (x += N; x > 1; x >>= 1)
	{
		y = tmp;
		for (y += N; y > 1; y >>= 1)
		{
			t[glob][x][y>>1] = min(t[glob][x][y], t[glob][x][y^1]);
			t[glob][x>>1][y] = min(t[glob][x][y], t[glob][x^1][y]);
		}
		t[glob][x>>1][y] = min(t[glob][x][y], t[glob][x^1][y]);
	}
}


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m >> p;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			dp[i][j] = MOD;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			g[a[i][j]].push_back(mp(i,j));
			if (a[i][j] == 1)
			   dp[i][j] = i+j;
			if (a[i][j] == p)
			   fx = i, fy = j;
		}
	for (i = 0; i <= N*2; i++)
		for (j = 0; j <= N*2; j++)
			for (k = 0; k < 4; k++)
				t[k][i][j] = MOD;
	//UR - dp[x2][y2] = dp[x1][y1] + x2-x1+y2-y1 = dp[x1][y1]-x1-y1+(x2+y2)
	//UL - dp[x2][y2] = dp[x1][y1] + x2-x1+y1-y2 = dp[x1][y1]-x1+y1+(x2-y2)
	//DR - dp[x2][y2] = dp[x1][y1] + x1-x2+y2-y1 = dp[x1][y1]-y1+x1+(y2-x1)
	//DL - dp[x2][y2] = dp[x1][y1] + x1-x2+y1-y2 = dp[x1][y1]+x1+y1+(-x2-y2)
	for (i = 2; i <= p; i++)
	{
		ll last_sz = g[i-1].size();
		for (j = 0; j < last_sz; j++)
		{
			ll x = g[i-1][j].X;
			ll y = g[i-1][j].Y;
			glob = 0;
			//cout << x << " " << y << " " << get( 0, x, 0, y) << "g" << endl;
			update(x,y,dp[x][y]-x-y);
			//cout << get( 0, x, 0, y) << "f" << endl;
			glob = 1;
			update(x,y,dp[x][y]-x+y);
			glob = 2;
			update(x,y,dp[x][y]+x-y);
			glob = 3;
			update(x,y,dp[x][y]+x+y);
		}
		ll cur_sz = g[i].size();
		for (j = 0; j < cur_sz; j++)
		{
			ll x = g[i][j].X;
			ll y = g[i][j].Y;
			glob = 0;
			//cout << get( 0, x, 0, y) << endl;
			dp[x][y] = min(dp[x][y], get( 0, x, 0, y)+x+y);
			glob = 1;
			dp[x][y] = min(dp[x][y], get(0, x, y, m-1)+x-y);
			glob = 2;
			dp[x][y] = min(dp[x][y], get(x, n-1, 0, y)-x+y);
			glob = 3;
			dp[x][y] = min(dp[x][y], get(x, n-1, y, m-1)-x-y);
		}
		for (j = 0; j < last_sz; j++)
		{
			ll x = g[i-1][j].X;
			ll y = g[i-1][j].Y;
			glob = 0;
			update(x,y,MOD);
			glob = 1;
			update(x,y,MOD);
			glob = 2;
			update(x,y,MOD);
			glob = 3;
			update(x,y,MOD);
		}
	}
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	cout << dp[fx][fy] << endl;
	return 0;
}
