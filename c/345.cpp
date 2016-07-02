#include<bits/stdc++.h>
using namespace std ;
int ax[1111111],ay[1111111],pa[1111111],ans[1111111],n,m,cnt,f[1111111] ;

struct node{
  int val,id,x,y ;
  bool operator <(const node &a ) const
  {
      return val<a.val ;
  }
} ;

int find(int x)
{
    if(pa[x]==x) return x ;
    return pa[x] = find(pa[x]) ;
}
node a[1111111] ;
int main()
{
    cin>>n>>m ;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            int p ; cin>>p ; ++cnt ;a[cnt] = (node){p,cnt,i,j+n} ;
        }
    }
    sort(a+1,a+1+cnt) ; int i , j ;
    for( i = 1;i<=cnt;i=j)
    {
        for(j = i;a[j].val==a[i].val;j++) ;
        for(int k = i;k<j;k++)
        {
            pa[a[k].x] = a[k].x ;
            pa[a[k].y] = a[k].y ;
            f[a[k].x] = f[a[k].y] = 0 ;
        }
        for(int k = i;k<j;k++)
        {
            int r1 = find(a[k].x) ;
            int r2 = find(a[k].y) ;
            pa[r1] = r2 ;
            f[r2] = max(f[r1],max(f[r2],max(ax[a[k].x],ay[a[k].y])) ) ;
        }
        for(int k= i;k<j;k++)
        {
            ans[a[k].id] = max( f[find(a[k].x) ] , f[find(a[k].y) ]  ) +1 ;
            ax[a[k].x] = max( ax[a[k].x] , ans[a[k].id] ) ;
            ay[a[k].y] = max(ay[a[k].y] , ans[a[k].id] ) ;
        }
    }
    cnt = 0 ;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0 ;j<m;j++)
        {
            cout<<ans[++cnt]<<" ";
        }
        cout<<endl ;
    }
}
