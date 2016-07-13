#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1], b[n+1];
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b+i);

    int desired_pos[n+1];
    for (int i = 1; i <= n; ++i)
        desired_pos[b[i]] = i;

    int acc = 0;
    vector<ii> ans;
    for (int i = n; i >= 1; --i) {
        int pos = i;
        for (int j = i+1; j <= desired_pos[a[pos]]; ++j) {
            if (desired_pos[a[j]] <= pos) {
                acc += abs(j-pos);
                ans.emplace_back(pos, j);
                swap(a[pos], a[j]);
                pos = j;
            }
        }
    }
    printf("%d\n", acc);
    printf("%d\n", (int) ans.size());
    for (const ii x : ans)
        printf("%d %d\n", x.first, x.second);
}
