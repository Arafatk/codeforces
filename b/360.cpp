/* Created by Anmol Varshney */

#include <stdio.h>
#include <string.h>
//#include <unordered_map>
//#include <unordered_set>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define REPR(p,a,b) for(int p=a;p>=b;p--)
#define mod 1000000007
#define getchar_unlocked getchar
#define pb(f) push_back(f)
#define pob(f) pop_back(f)
#define pf(f) push_front(f)
#define pof(f) pop_front(f)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
#define pii pair<int,int>
#define ins(a) insert(a)
#define FAST_LOG2(x) (sizeof(unsigned long)*8 - 1 - __builtin_clzl((unsigned long)(x)))
#define IOS ios_base::sync_with_stdio(false)
#define citi cin.tie(NULL);
#define FREI(var) freopen(var,"r",stdin)
#define FREO(var) freopen(var,"w",stdout)

ll gcd(ll a,ll b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return gcd(b,a%b);
    else return a;
}

int main()
{
    //FREI("input.txt");
    //FREO("output.txt");
    IOS;
    //citi;
    ll n,k,x,prod=1;
    cin>>n>>k;
    REP(i,0,n)
    {
        cin>>x;
        prod=prod*x/gcd(prod,x);
        prod=gcd(prod,k);
    }
    if(prod!=k) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}
