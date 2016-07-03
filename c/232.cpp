#include<bits/stdc++.h>

#define MOD 1000000007
#define MAX 300005
#define ll long long
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define vpii vector<pii >
#define vll vector<ll>
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

vi adj[MAX];
int father[MAX];

int st[MAX],en[MAX],depth[MAX],global=0;

void preDFS(int ind){
	st[ind]=++global;
	depth[ind]=1+depth[father[ind]];
	for(int i=0;i<adj[ind].size();i++) preDFS(adj[ind][i]);
	en[ind]=global;
}

pii segTree[MAX<<2];

inline void add(pii &a,const pii &b){
	a.FF+=b.FF;a.SS+=b.SS;
	if(a.FF>=MOD) a.FF-=MOD;
	if(a.SS>=MOD) a.SS-=MOD;
}

void update(int t,int i,int j,const int &ri,const int &rj,const pii &upd){
	if(ri<=i && j<=rj){
		add(segTree[t],upd);
		return;
	}
	int left = t<<1,right=left|1,mid=(i+j)>>1;
	if(ri<=mid) update(left,i,mid,ri,rj,upd);
	if(rj>mid) update(right,mid+1,j,ri,rj,upd);
}

pii query(int t,int i,int j,const int &idx,pii par){
	add(par,segTree[t]);
	if(i==j) return par;
	int left = t<<1,right=left|1,mid=(i+j)>>1;
	if(idx<=mid) return query(left,i,mid,idx,par);
	return query(right,mid+1,j,idx,par);
}

int main(){
	int n;sd(n);
	for(int i=2;i<=n;i++){
		int x;sd(x);
		adj[x].pb(i);
		father[i]=x;
	}
	
	father[1]=0;depth[0]=0;
	preDFS(1);
	
	int q;sd(q);
	while(q--){
		
		int type;sd(type);
		if(type==1){
			int v,x,k;
			sd(v);sd(x);sd(k);
			update(1,1,n,st[v],en[v],mp((x+depth[v]*1LL*k)%MOD,k));
		}else{
			int v;
			sd(v);
			
			pii got=query(1,1,n,st[v],mp(0,0));
			int ans=(got.FF-((depth[v]*1LL*got.SS)%MOD)+MOD)%MOD;
			pd(ans);
		}
	}
}
