#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n,m,i,j,kcnt,kl,kr,x,y;
char s[1000005];

struct f{
   int l,r,cnt;
}tree[4000005];

void build(int l, int r, int ind){
   if(l == r){
      if(s[l - 1] == '(')
      tree[ind].l++;
      else
      tree[ind].r++;
      return;
   }
   int mid = (l + r) / 2;
   build(l, mid, ind * 2);
   build(mid + 1, r, ind * 2 + 1);
   int val = min(tree[ind * 2].l, tree[ind * 2 + 1].r);
   tree[ind].cnt = tree[ind * 2].cnt + tree[ind * 2 + 1].cnt + val;
   tree[ind].l = tree[ind * 2].l + tree[ind * 2 + 1].l - val;
   tree[ind].r = tree[ind * 2].r + tree[ind * 2 + 1].r - val;
}

void query(int l, int r, int ind){
   if(x <= l && r <= y){
      int val = min(kl, tree[ind].r);
      kcnt += tree[ind].cnt + val;
      kl += tree[ind].l - val;
      kr += tree[ind].r - val;
      return;
   }
   int mid = (l + r) / 2;
   if(x <= mid)
   query(l, mid, ind * 2);
   if(y > mid)
   query(mid + 1, r, ind * 2 + 1);
}

int main(){
   scanf("%s", s);
   n = strlen(s);
   build(1, n, 1);
   scanf("%d", &m);
   for(i = 0; i < m; i++){
      scanf("%d%d", &x, &y);
      kcnt = 0;
      kl = 0;
      kr = 0;
      query(1, n, 1);
      printf("%d\n", kcnt * 2);
   }
}