#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 10000000000000000
#define MAX 300000+5
using namespace std;
vector<pair<ll,ll> > adj[MAX],s;
map< pair<ll,ll>,pair<ll,ll> > my;
ll dis[MAX],path[MAX];
void dijkstra(ll src,ll n,ll dist[])
{
	ll d,idx,id,p;
	rep(i,0,n)
	{
		dist[i]=INF;
		path[i]=i;
	}
	dist[src]=0;
	set<pair<ll,ll> > v;
	typeof(v.begin()) it;
	rep(i,0,n)
	v.insert(mp(dist[i],i));
	while(v.size())
	{
		it=v.begin();
		d=it->first;
		idx=it->second;
		if(idx!=path[idx])
		s.pb(mp(idx,path[idx]));
		v.erase(it);
		rep(i,0,adj[idx].size())
		{
			id=adj[idx][i].first;
			p=adj[idx][i].second;
			if(dist[id]>=p+d)
			{
				it=v.find(mp(dist[id],id));
				v.erase(it);
				dist[id]=p+d;
				path[id]=idx;
				v.insert(mp(dist[id],id));
			}
		}
	}
	return;
}
int main()
{
	ll n,m,x,y,p,ans;
	scll(n); scll(m);
	rep(i,0,m)
	{
		scll(x); scll(y); scll(p);
		x--; y--;
		adj[x].pb(mp(y,p));
		adj[y].pb(mp(x,p));
		my.insert(mp(mp(x,y),mp(i+1,p)));
	}
	scll(p);
	p--;
	dijkstra(p,n,dis);
	
	ll sum=0;
	vector<ll> v;
	typeof(my.begin()) it;
	rep(i,0,s.size())
	{
		x=s[i].first;
		y=s[i].second;
		it=my.find(mp(x,y));
		if(it==my.end())
		it=my.find(mp(y,x));
		v.pb(it->second.first);
		sum+=it->second.second;
	}
	sort(v.begin(),v.end());
	printf("%lld\n",sum);
	rep(i,0,v.size())
	printf("%lld ",v[i]);
	return 0;
}
