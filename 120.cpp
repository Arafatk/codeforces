// God & me
// Life is ruined and love is lost :'(
// @Yazd
#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
//#define int long long
using namespace std;
template <class T, class L> bool smax(T &x,L y){  return x < y ? (x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x,L y){  return y < x ? (x = y, 1) : 0;  }
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 4e5 + 17;
int n;
string ans, s;
vector<string> v;
int go(int st = 0){
    if(st >= v.size())
	cout << "Error occurred\n" << '\n', exit(0);
    if(v[st] == "int")
	return ans += "int", st + 1;
    ans += "pair<";
    int ta = go(st + 1);
    ans += ",";
    ta = go(ta);
    ans += ">";
    return ta;
}
main(){
    ios::sync_with_stdio(0), cin.tie(0);
    {  int tmp;  cin >> tmp;  }
    while(cin >> s){
	if(s == "pair" || s == "int")
	    v.pb(s);
	else
	    break;
    }
    if(go() != v.size())
	cout << "Error occurred\n" << '\n', exit(0);
    cout << ans << '\n';
    return 0;
}
