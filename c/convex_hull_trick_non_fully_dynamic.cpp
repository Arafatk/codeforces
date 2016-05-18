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
void print(){cout <<"\n";};
template<typename T,typename... Args>
void print(T &a, Args&... args) {  cout << a << " "  ; print(args...); }
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
#define ll unsigned long long
#define st string
#define ld long double

ll a[110000], b[110000], n, dp[110000], sum[110000], best;

class line
{
    public:
      ll m, c;
      line() {};
      line(ll a,ll b): m(a), c(b) {}; 
};
main()
{   
   boost;
   vector<line> l;
   r(n);
   fa(i,1,n+1)r(a[i]); 
   fa(i,1,n+1)r(b[i]);
   l.pb(line(b[1], 0));
// fa(i, 1, n + 1)fa(j, 1, i)dp[i] = miN(dp[i], dp[j] + a[i] * b[j]);  brute
   fa(i, 2, n + 1)
   {
      while(best < (l.size()-1) && (a[i]*l[best].m + l[best].c > a[i] * l[best + 1].m + l[best + 1].c))
         best++;
      dp[i] = a[i]*l[best].m + l[best].c;
      while(l.size() >= 2)
      {
         ll m1 = l[l.size()-2].m, p1 = l[l.size()-2].c;
         ll m2 = l[l.size()-1].m, p2 = l[l.size()-1].c;
         ll m3 = b[i], p3 = dp[i];
         if((double)(p2-p1)*(double)(m1-m3) >= (double)(p3-p1)*(double)(m1-m2))
            l.pop_back();
         else
            break;
      }
      l.pb(line(b[i],dp[i]));
   }
   cout << dp[n] << endl;
} 