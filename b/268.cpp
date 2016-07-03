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
int upsie[112345], downsie[112345], vals[112345], arr[112345], n, a, b;
std::map<int, int> taper;
main()
{ 
  boost;
  r(n, a, b);
  fa(i,1,n+1){r(arr[i]);taper[arr[i]] = i;
  upsie[i]   = -1;
  downsie[i] = -1;
  vals[i]    = -1;
  };

  fa(i,1,n+1){
    if(taper[a - arr[i]] != 0)upsie[i]   = taper[a - arr[i]]; // Add a connect up
    if(taper[b - arr[i]] != 0)downsie[i] = taper[b - arr[i]]; // Add a connect down
  }
  fa(i,1,n+1) if(upsie[i] == -1 and downsie[i] == -1){p("NO");exit(0);}
//  fa(i,1,n+1)p("upsie", upsie[i], "downsie",downsie[i],i);
  fa(i,1,n+1)
  {
    if(vals[i] == -1 and ( (a==b) or (upsie[i] != -1 and downsie[i] == -1) || (upsie[i] == -1 and downsie[i] != -1)))
    {
     //  p(i, " Started with this index");
       int index_mov = i;
       int brake = 0;
       if(upsie[i] != -1 )
       {
          while(brake == 0)
          {
         //   p(index_mov);
            if(vals[index_mov] != -1 && downsie[index_mov] != index_mov){p("NO");exit(0);};
            vals[index_mov] = 0;
            index_mov = upsie[index_mov];
            if(upsie[i] == -1)        {p("NO");exit(0);};
            if(vals[index_mov] != -1 && upsie[index_mov] != index_mov){p("NO");exit(0);};
          //  p(index_mov); 
            vals[index_mov] = 0;
            if(vals[downsie[index_mov]] != -1) {brake = 1; break;}
            index_mov = downsie[index_mov];
            if(index_mov == -1 ) brake = 1;
          };
       };
       
       if(downsie[i] != -1)
       {
          while(brake == 0)
          { 
          //  p(index_mov, " down", downsie[index_mov]); 
            if(vals[index_mov] != -1 && upsie[index_mov] != index_mov) {p("NO");exit(0);};
            vals[index_mov] = 1;
            index_mov = downsie[index_mov];
            if(downsie[index_mov] == -1)      {p("NO");exit(0);};

           // p(index_mov, " down", upsie[index_mov]);
            if(vals[index_mov] != -1 && downsie[index_mov] != index_mov) {p("NO");exit(0);};
            vals[index_mov] = 1;
            if(vals[upsie[index_mov]] != -1) {brake = 1; break;}
            index_mov = upsie[index_mov];
            if(index_mov == -1 ) brake = 1;
          };
       };


    };
  };
  p("YES");
  fa(i,1,n+1)cout << (vals[i]) << " "; 
  cout << "\n";

} 
