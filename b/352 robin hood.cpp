#include<bits/stdc++.h>
 
using namespace std;
 
#define pii pair<int,int>
#define ll long long
#define N (int)(5e5+10)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define nd second
#define st first
#define inf mod
#define endl '\n'
#define sag (sol|1)
#define sol (root<<1)
#define bit(x,y) ((x>>y)&1)
 
ll t;
int a[N],i,j,k,n,m,x,y,z;
 
int main(){
  cin >> n >> k;
 
  for(i=1 ; i<=n ; i++)
    scanf("%d",a+i);
 
  int bas=1, son=2*inf;
 
  while(bas<son){
    int ort = ((ll)bas+son)/2;
    if(bas==ort)
      ort++;
    t = 0;
    for(i=1 ; i<=n ; i++)
      t += max(0 , ort-a[i]);
    if(t <= k)
      bas = ort;
    else
      son = ort-1;
  }
 
  t = k;
 
  for(i=1 ; i<=n ; i++){
    t -= max(0 , bas-a[i]);
    a[i] = max(a[i] , bas);
  }
 
  for(i=1 ; i<=n ; i++)
    if(a[i] == bas and t){
      t--;
      a[i]++;
    }
 
  bas=1, son=2*inf;
 
  while(bas<son){
    int ort = ((ll)bas+son)/2;
    t = 0;
    for(i=1 ; i<=n ; i++)
      t += max(0 , a[i]-ort);
    if(t <= k)
      son = ort;
    else
      bas = ort+1;
  }
 
  t = k;
 
  for(i=1 ; i<=n ; i++){
    t -= max(0 , a[i]-bas);
    a[i] = min(a[i] , bas);
  }
 
  for(i=1 ; i<=n ; i++)
    if(a[i] == bas and t){
      t--;
      a[i]--;
    }
 
  cout << *max_element(a+1,a+1+n) - *min_element(a+1,a+1+n) << endl;
 
}
