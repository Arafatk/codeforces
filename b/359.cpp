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

int parent[1123456], query, n, node, child[1123456], visited[1123456], centroid[1123456] , visti[1123456];
std::vector<std::vector<int> > graph;
int dfs(int vertex)
{
	visited[vertex]=1;//cout << vertex << "->";
    fe(i,graph[vertex])if(!visited[i])child[vertex] += dfs(i);
    child[vertex] += graph[vertex].size() - 1;
    return child[vertex];
};

struct noder{
    int index, children;
    noder(int a, int b) : children(a), index(b){};
    bool operator<(struct noder const & other) const {return children > other.children;}
};

void dfs_childer(int vertex)
{
    visti[vertex]=1;
    int max_node = 0,max_val = 0;
    int sz = graph[vertex].size();
    if (graph[vertex].size() == 1 and vertex != 1) { centroid[vertex] = vertex; return ;}

    fe(i,graph[vertex]) 
    if(child[i] >= max_val && i != parent[vertex]){max_val = child[i]; max_node = i;};

    fe(i,graph[vertex])if(!visti[i])dfs_childer(i);

    
    int center = centroid[max_node];
    while(child[center] * 2 < child[vertex] )
    {
    //	p("center", center,"vertex",vertex);
    	if(parent[center] != -1 ) center = parent[center];
    	else break;
    	
    };
    centroid[vertex] = center;	
    return;
} 

main()
{ 
	boost;
	r(n, query);
	fa(i,2, n+1){r(node); parent[i] = node;}
	parent[1] = -1;
	std::vector<int> node_vec;
	fa(i,0,n+2) graph.pb(node_vec);
	fa(i,2,n+1){int node2 = parent[i];graph[node2].pb(i);graph[i].pb(node2);}
    dfs(1);child[1]++;
    parent[1] = -1;
    parent[0] = -1;
    visti[0] = 1;
    dfs_childer(1);
    fa(i,0,query){r(n);p(centroid[n]);}
    

} 
