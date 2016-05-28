#include <bits/stdc++.h>
using namespace std;

#define INF                         (int)1e9
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3


/* const clock_t begin_time = clock();
   // do something
std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
*/

template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }

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

// The vectors and pairs
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int>pa;
#define ft                 first
#define sd                 second

// the data types
#define ll long long
#define st string
#define ld long double

string arena[5100];
int dpl[5100][5100],dpu[5100][5100],h,w;
void leftfill(int row,int columns)
{
    int rowcounty=0;
    fa(i,1,columns)
    {
       if(arena[0][i]=='.' && arena[0][i-1]=='.')rowcounty++;
       dpl[0][i]=rowcounty; 
    }
    fa(i,1,row)
    {
        rowcounty=0;
        fa(j,1,columns)
        {
            if(arena[i][j]=='.' && arena[i][j-1]=='.')rowcounty++;
            dpl[i][j]=dpl[i-1][j]+rowcounty;
        }

    }
}
void ufill(int row,int columns)
{
    int rowcounty=0;
    fa(j,1,columns)dpu[0][j]=0;
    fa(i,1,row)
    {
        rowcounty=0;
        fa(j,0,columns)
        {
            if(arena[i][j]=='.' && arena[i-1][j]=='.')rowcounty++;
            dpu[i][j]=dpu[i-1][j]+rowcounty;
        }

    }
}
int upper(int a,int b,int c,int d)
{
    a--;b--;c--;d--;
   int ansup=dpu[c][d];
   if(b>0)ansup-=dpu[c][b-1];
   if(a>0)ansup-=dpu[a][d];
   if(a>0 && b>0)ansup+=dpu[a][b-1];
   return ansup;

}
int lefter(int a,int b,int c,int d)
{
    a--;b--;c--;d--;
   int ansup=dpl[c][d];
   if(b>0)ansup-=dpl[c][b];
   if(a>0)ansup-=dpl[a-1][d];
   if(a>0 && b>0)ansup+=dpl[a-1][b];
   return ansup;

}

main()
{  
    cin >> h >> w;
    fa(i,0,h)cin >> arena[i];
    leftfill(h,w);ufill(h,w);
    int y=10;cin >> y;
    while(y--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << upper(a,b,c,d)+lefter(a,b,c,d) << "\n";
    }
}
