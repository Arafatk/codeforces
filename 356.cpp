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

int parent[1123456], query, node, child[1123456], centroid[1123456] , visti[1123456];
int gifto[112345], n, m, visited[1123456], node1, node2, nonparent[112345];
std::vector<std::vector<int> > graph;
std::deque<int> results;
int dfs(int vertex, int nowter)
{
	visited[vertex] = 1;
//	p("vertex", vertex, "nowter",nowter);
	if(gifto[vertex] == nowter || gifto[vertex] == vertex)
	{

		if(gifto[vertex] == vertex){ results.push_back(vertex); nowter = vertex;};
		int yes = 1;
		fe(i,graph[vertex])if(!visited[i]){yes = dfs(i,nowter); if(yes == -1 )return -1;}
		return 1;
	}
	//p(vertex, "vertex not reached");
    return -1;
};


main()
{ 
	boost;
	std::vector<int> node_Vec;
	r(n, m);
	fa(i,0,n+1){graph.pb(node_Vec);};
	fa(i,0, m){r(node1,node2); 
		         graph[node1].pb(node2);
		         nonparent[node2] = 1;}
    fa(i,0,n) {r(node1); gifto[i+1] = node1; }		
    int top=0, yes;
    fa(i,1,n+1) if(nonparent[i] == 0)
    {
    	yes = dfs(i, i);
    	if(yes == -1) break;
    }
    if (yes == 1) cout << results.size() << endl;
    if(yes == 1)
    while(!results.empty())
    {
    	cout << results.back() << endl;
    	results.pop_back();
    }
    else cout << "-1\n";


    

} 
