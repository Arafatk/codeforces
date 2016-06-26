#include <bits/stdc++.h>
using namespace std;

const int NM = 20, MASK = (1 << 18) + 10;

int n, m, k;
int a[NM], inc[NM][NM];
long long dp[MASK][NM];

long long solve(int mask = 0, int last = n){
    if(__builtin_popcount(mask) == m){
        return 0;
    }
    long long &ret = dp[mask][last];
    if(ret == -1){
        ret = -1e18;
        for(int i = 0; i < n; i++) if(!(mask & (1 << i))){
            ret = max(ret, a[i] + inc[last][i] + solve(mask | (1 << i), i));
        }
    }
    return ret;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= k; i++){
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        inc[x - 1][y - 1] = c;
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve());
    return 0;
}
