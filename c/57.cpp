#include <bits/stdc++.h>
using namespace std;
#define INF                         (int)1e9
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3

 
/* 
   const clock_t begin_time = clock();
   // do something
   cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

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
template<class T> T lcm(T a, T b) { return  ((a*b)/gcd (b % a, a)); }
template<class T> T binpow(T number, T power) { T result = 1; while(power) { if(power & 1) result *= number; number *= number;power /= 2;}return result;}
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// Useful container manipulation / traversal macros
#define fa(i, begin, end)           for (auto i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fe(v, c)                    for(auto v :c)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          emplace_back  // this will work almost always
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((auto)(a.size()))
#define mt                          make_tuple
// comparision Guys 
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define abs(a)                      ( (a) > (0) ? (a) : (-a))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)               ( (n >> b) & 1)
#define DREP(a)                     sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat
#define sqr(x)                      ((x) * (x))
#define sqrt(x)                     sqrt(abs(x))
// The bit standard guys
#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define higbit(x)                   (1 << ( auto) log2(x) )
 
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

ll result2[1123456];
ll result[1123456];
ll tree2[4123456];
ll tree[4123456];
ll n;
class Segtree{
    public:

    void init()
    {
    };

    void update(ll p,ll id = 1,ll l = 0,ll r = n){
      if(r - l < 2){
        tree[id] = 1;
        return ;
      }
      ll mid = (l+r)/2;
      if(p < mid)
        update(p, 2 * id, l, mid);
      else
        update(p, 2 * id + 1, mid, r);
      tree[id] = tree[2 * id] + tree[2 * id + 1];
    };

    ll sum(ll x,ll y,ll id = 1,ll l = 0,ll r = n){// [x, y)
      if(x >= r or l >= y)  return 0;// [x, y) llersection [l,r) = empty
      if(x <= l && r <= y)  // [l,r) is a subset of [x,y)
      return tree[id];
      ll mid = (l + r)/2;
      return sum(x, y, id * 2, l, mid) +
             sum(x, y, id*2+1, mid, r) ;
    };

};

ll arr[1123456];

struct cmp {
  bool operator() (const tuple<ll, ll> a, const tuple<ll, ll> b) const {
    return get<0>(a) < get <0>(b); 
  };
};

main()
{ 
  boost;
  std::vector<tuple<ll, ll> > v;
  r(n);
  fa(i,0,n){r(arr[i]);v.pb(mt(arr[i],i));};
  sort(v.begin(),v.end(),cmp());
  Segtree inverter;
  inverter.init();
  fe(i,v)
  {
     inverter.update(get<1>(i));
     result[get<1>(i)] = inverter.sum(get<1>(i)+1,n);
  };
 // fa(i,0,n)p(i,arr[i],result[i]);
  fe(i,v)
  {
     result2[get<1>(i)] = inverter.sum2(get<1>(i)+1,n);
     inverter.update2(get<1>(i));
  };
//  cout << endl << endl;
  ll resultewr = 0;
  fa(i,0,n)resultewr+=result2[i];
  p(resultewr);
} 
