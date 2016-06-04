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

/*
 * Dynamic version of data structure
 * to be used in dynamic programming optimisation
 * called "Convex Hull trick"
 * 'Dynamic' means that there is no restriction on adding lines order
 */
class ConvexHullDynamic
{
    typedef long long coef_t;
    typedef long long coord_t;
    typedef long long val_t;
 
    /*
     * Line 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * and 'xLeft' which is intersection with previous line in hull(first line has -INF)
     */
private:
    struct Line
    {
        coef_t a, b;
        double xLeft;
 
        enum Type {line, maxQuery, minQuery} type;
        coord_t val;
 
        explicit Line(coef_t aa=0, coef_t bb=0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}
        val_t valueAt(coord_t x) const { return a*x+b; }
        friend bool areParallel(const Line& l1, const Line& l2) { return l1.a==l2.a; }
        friend double intersectX(const Line& l1, const Line& l2) { return areParallel(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }
        bool operator<(const Line& l2) const
        {
            if (l2.type == line)
                return this->a     < l2.a;
            if (l2.type == maxQuery)
                return this->xLeft < l2.val;
            if (l2.type == minQuery)
                return this->xLeft > l2.val;
        };
    } ;
 
private:
    bool            isMax; //whether or not saved envelope is top(search of max value)
    std::set<Line>  hull;  //envelope itself
 
private:
    /*
     * INFO:        Check position in hull by iterator
     * COMPLEXITY:  O(1)
     */
    bool hasPrev(std::set<Line>::iterator it) { return it!=hull.begin(); }
    bool hasNext(std::set<Line>::iterator it) { return it!=hull.end() && std::next(it)!=hull.end(); }
 
    /*
     * INFO:        Check whether line l2 is irrelevant
     * NOTE:        Following positioning in hull must be true
     *              l1 is next left to l2
     *              l2 is right between l1 and l3
     *              l3 is next right to l2
     * COMPLEXITY:  O(1)
     */
    bool irrelevant(const Line& l1, const Line& l2, const Line& l3) { return intersectX(l1,l3) <= intersectX(l1,l2); }
    bool irrelevant(std::set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it)
               && (    isMax && irrelevant(*std::prev(it), *it, *std::next(it))
                       || !isMax && irrelevant(*std::next(it), *it, *std::prev(it)) );
    }
 
    /*
     * INFO:        Updates 'xValue' of line pointed by iterator 'it'
     * COMPLEXITY:  O(1)
     */
    std::set<Line>::iterator updateLeftBorder(std::set<Line>::iterator it)
    {
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it))
            return it;
 
        double val = intersectX(*it, isMax?*std::prev(it):*std::next(it));
        Line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }
 
public:
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}
 
    /*
     * INFO:        Adding line to the envelope
     *              Line is of type 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * COMPLEXITY:  Adding N lines(N calls of function) takes O(N*log N) time
     */
    void addLine(coef_t a, coef_t b)
    {
        //find the place where line will be inserted in set
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);
 
        //if parallel line is already in set, one of them becomes irrelevant
        if (it!=hull.end() && areParallel(*it, l3))
        {
            if (isMax && it->b < b || !isMax && it->b > b)
                it = hull.erase(it);
            else
                return;
        }
 
        //try to insert
        it = hull.insert(it, l3);
        if (irrelevant(it)) { hull.erase(it); return; }
 
        //remove lines which became irrelevant after inserting line
        while (hasPrev(it) && irrelevant(std::prev(it))) hull.erase(std::prev(it));
        while (hasNext(it) && irrelevant(std::next(it))) hull.erase(std::next(it));
 
        //refresh 'xLine'
        it = updateLeftBorder(it);
        if (hasPrev(it))
            updateLeftBorder(std::prev(it));
        if (hasNext(it))
            updateLeftBorder(std::next(it));
    }
    /*
     * INFO:        Query, which returns max/min(depends on hull type - see more info above) value in point with abscissa 'x'
     * COMPLEXITY:  O(log N), N-amount of lines in hull
     */
    val_t getBest(coord_t x) const
    {
        Line q;
        q.val = x;
        q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;
 
        auto bestLine = hull.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->valueAt(x);
    }
};

	ll a[110000], b[110000], n, dp[110000], sum[110000], best;


main()
{   
   boost;
   ConvexHullDynamic rama(1);
   r(n);
   fa(i,1,n+1)r(a[i]); 
   fa(i,1,n+1)r(b[i]);
   rama.addLine(-b[1], 0);
// fa(i, 1, n + 1)fa(j, 1, i)dp[i] = miN(dp[i], dp[j] + a[i] * b[j]);  brute
   fa(i, 2, n + 1)
   {
      
      dp[i] = -rama.getBest(a[i]);
      rama.addLine(-b[i],-dp[i]);
   }


   cout << dp[n] << endl; 
} 
