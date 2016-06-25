#include <bits/stdc++.h>
using namespace std;
#define INF                         (int)1e9
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
 
/* 
   const clock_t begin_time = clock();
   // do something
   cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
*/

/*
 Read from a file
 freopen("input.in","r",stdin);
 freopen("output.out","w",stdout);
*/   
void r(){};
template<typename T,typename... Args>
void r(T &a, Args&... args) {  cin>>a ; r(args...); }
void p(){cout <<"\n";};
template<typename T,typename... Args>
void p(T &a, Args&... args) {  cout << a << " "  ; p(args...); }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// Useful container manipulation / traversal macros
#define fa(i, begin, end)           for (auto i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fe(v, c)                    for(auto v :c)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          emplace_back  // this will work almost always
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((auto)(a.size()))
#define mp                          make_pair
// comparision Guys 
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define abs(a)                       ( (a) > (0) ? (a) : (-a))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat
#define sqr(x)                       ((x) * (x))
#define sqrt(x)                       sqrt(abs(x))
// The bit standard guys
#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define higbit(x)                   (1 << ( auto) log2(x) )
#define what_is(x) cerr << #x << " is " << x << endl;
 
// The vectors and pairs
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int>pa;
#define ft                 first
#define sd                 second
#define pq                 priority_queue
// the data types
#define ll long long
#define st string
#define ld long double
int n, m;
vector<vector<int> > graph;
vector<vector<int> > tree;
int cities[123459], visited[123459], parent[123459], vis[123459];

void graph_maker(int vertex)
{
   visited[vertex] = 1; //cout << vertex << " ->";
   fe(i,graph[vertex])if(!visited[i]){parent[i] = vertex;graph_maker(i);}

   fe(i,graph[vertex])
   {
   	   if(i != parent[vertex] && cities[i] == 1)
   	   	 {
   	   	 	cities[vertex] = 1;
   	   	 	tree[vertex].pb(i);
   	   	 	tree[i].pb(vertex);
   	   	 }
   }
}

void dfs(int vertex)
{
	vis[vertex]=1; // cout << vertex << "->";
    fe(i,tree[vertex])if(!vis[i])dfs(i);
}

int smallest_diim, diammer, dist[123459];
void farthest(int vertex)
{
    vis[vertex] = 1;
    fe(i,tree[vertex])
    {
    	if(!vis[i]){        dist[i] = dist[vertex] + 1;
    	 if(dist[i] > diammer)  { diammer = dist[i]; smallest_diim = i;};
    	 if(dist[i] == diammer) { smallest_diim = miN(i,smallest_diim);};
    	  farthest(i);};
    	  if(dist[i] == diammer) { smallest_diim = miN(i,smallest_diim);};
    }
    
}

main()
{ 
	boost;
	std::vector<int> graph_node;
	r(n,m);
	fa(i,0,n+2){graph.pb(graph_node);tree.pb(graph_node);}
	fa(i,0,n-1)
	{
		int a, b;
		r(a,b);
		graph[a].pb(b);
		graph[b].pb(a);
	}
	fa(i,0,m){int a;r(a);cities[a] = 1;}
	int top = 0;
    fa(i,1,n+1){if(cities[i] == 1){graph_maker(i);top = i;break;}}
    dfs(top);
    fa(i,1,n+1)vis[i] = 0;
    smallest_diim = top;
    farthest(smallest_diim);
    fa(i,1,n+1)dist[i] = 0;
    fa(i,1,n+1)vis[i] = 0;
    farthest(smallest_diim);
    int sizer= 0;
    fa(i,1,n+1) if(tree[i].size() > 0)sizer++;
    int treevap = (sizer - 1) * 2 - diammer;
    p(smallest_diim);
    if(treevap!=-2)p(treevap); else p("0");


} 

/*
7 2
1 2
1 3
1 4
3 5
3 6
3 7
2 7


6 4
1 2
2 3
2 4
4 5
4 6
2 4 5 6

*/
