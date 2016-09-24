#include <bits/stdc++.h>
using namespace std;
#define inf                         INFINITY
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3

/* 
   const clock_t begin_time = clock();
   // do something
   cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

   Read from a file
   
   
*/

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void r(){};
template<typename T,typename... Args>
void r(T &a, Args&... args) {  cin>>a ; r(args...); }

void p(){cout <<"\n";};
template<typename T,typename... Args>
void p(T &a, Args&... args) {  cout << a << " "  ; p(args...); }

template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { return  ((a*b)/gcd (b % a, a)); }
template<class T1, class T2> T1 binpow(T1 number, T2 power) { T1 result = number; while(power) { if(power & 1) result = result*number; number = number*number;power /= 2;}return result;}

#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define fa(i, begin, end)           for (auto i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fe(v, c)                    for(auto v :c)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ((b).find(a) != (b).end())
#define pb                          emplace_back  // this will work almost always
#define fill(a,v)                   memset(a, v, sizeof a)
#define sz(a)                       ((auto)(a.size()))
#define mt                          make_tuple

#define abs(a)                      ((a) > (0) ? (a) : (-a))
#define checkbit(n,b)               ((n >> b) & 1)
#define DREP(a)                     sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat
#define sqr(x)                      ((x) * (x))
#define sqrt(x)                     sqrt(abs(x))

#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define higbit(x)                   (1 << (auto) log2(x) )

#define ft                          first
#define sd                          second
#define pq                          priority_queue

#define ll long long
#define st string
#define ld long double

ll fibonaa[112345], arr[112345], mod = 1000000007, queries;
ll n;
class Segtree{
public:
    ll *lazy, *array, *fibo, *fibo2;
    Segtree(ll *arr, ll sz){
      array = new ll[sz];
      lazy = new ll[4*sz];
      fibo = new ll[4*sz];
      fibo2 = new ll[4*sz];
      n = sz;
      fa(i,0,n) array[i] = arr[i];
      fa(i,0,4*sz) lazy[i] = 0;
      fa(i,0,4*sz) fibo[i] = 0;
      fa(i,0,4*sz) fibo2[i] = 0;
      build();
    }

    void build(ll id = 1, ll l = 0, ll r = n){
        if(r - l < 2) {
          fibo2[id] = fibonaa[array[l]+1]%mod; 
          fibo[id]  = fibonaa[array[l]]%mod; 
          return;
        }
        auto mid = (l+r)/2;
        build(2*id, l, mid); build(2*id+1, mid, r);
        fibo2[id] = (fibo2[2*id]   + fibo2[2*id + 1])%mod;
        fibo[id]  = (fibo[2*id]   +  fibo[2*id + 1])%mod;
    }


    ll sum1(ll x, ll y, ll id = 1, ll l = 0, ll r = n){
        if(l>= y or r <= x) return 0;
        if(l >= x and r<= y) return fibo[id];
        shift(id,l,r);
        auto mid = (l+r)/2;
        return (sum1(x,y,2*id,l,mid) + sum1(x,y,2*id+1,mid,r))%mod;
    }

    void upd(ll id,ll l,ll r,ll x){// increase all members in this llerval by x
      if(x == 0) return;
      lazy[id] += x;
      auto sum_of_n   = fibo[id];
      auto sum_of_n_2 = fibo2[id];
      fibo[id] =  ((sum_of_n_2*fibonaa[x])%mod + (sum_of_n*fibonaa[x-1])%mod)%mod;
      fibo2[id] = ((sum_of_n_2*fibonaa[x+1])%mod + (sum_of_n*fibonaa[x])%mod)%mod;
     }

    void shift(ll id,ll l,ll r){//pass update information to the children
       ll mid = (l+r)/2;
       upd(id * 2, l, mid, lazy[id]);
       upd(id * 2 + 1, mid, r, lazy[id]);
       lazy[id] = 0;// passing is done
    }

    void range_update(ll x, ll y, ll val, ll id = 1, ll l = 0, ll r = n){
        if(l>= y or r <= x) return;
        if(x <= l and r<= y) {upd(id, l, r, val); return;}
        shift(id,l,r);
        auto mid = (l+r)/2;
        range_update(x,y,val,2*id,l,mid);
        range_update(x,y,val,2*id+1,mid,r);
        fibo2[id] = (fibo2[2*id]   + fibo2[2*id + 1])%mod;
        fibo[id]  = (fibo[2*id]   +  fibo[2*id + 1])%mod;
    }
};
main()
{ 
  boost;
    fibonaa[1] = 1;fibonaa[2] = 1;fa(i,3,112345){fibonaa[i]= (fibonaa[i-1]+fibonaa[i-2])%mod;}
    r(n,queries);
    fa(i,0,n)r(arr[i]);
    Segtree tree(arr, n);
    
    fa(i,0,queries){
      int type, a, b , c;
      r(type,a,b);
      if(type == 1){r(c); tree.range_update(a-1,b,c); }
      if(type == 2){auto  ans = (tree.sum1(a-1,b));p(ans);};
    }
} 