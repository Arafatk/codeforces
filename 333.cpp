#include <iostream>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;
const int nmax = 131072, inf = 1 << 29;
int n, a[nmax], l[nmax], r[nmax];
ll ans;
int main()
{
	int i, j, q, u, v;
	cin >> n >> q;
	for (i = 0; i < n; i++)
		scanf("%d", a + i);
	for (i = n - 1; i; i--)
		a[i] = abs(a[i] - a[i - 1]);
	a[0] = a[n] = inf;
	n--;
	/*for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");*/
	l[0] = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = i - 1; a[j] <= a[i]; j = l[j]);
		l[i] = j;
	}
	r[n + 1] = n + 1;
	for (i = n; i; i--) 
	{
		for (j = i + 1; a[j] < a[i]; j = r[j]);
		r[i] = j;
	}
	/*for (i = 1; i <= n; i++)
		printf("l %d  r %d\n", l[i], r[i]);*/
	while (q--)
	{
		scanf("%d%d", &u, &v);
		v--;
		ans = 0;
		for (i = u; i <= v; i++)
			ans += (i - max(l[i], u - 1)) * ll(min(r[i], v + 1) - i) * a[i];
		printf("%I64d\n", ans);
	}
	return 0;
}
