#include <bits/stdc++.h>
using namespace std;

int n, m;
int a;
int p[100005];
int b[100005];

int main()
{
	scanf("%d %d %d", &n, &m, &a);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", b+i);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", p+i);
	}

	sort(b, b+n);
	sort(p, p+m);

	int lo = 0;
	int hi = min(n, m);
	int md;
	

	while (lo <= hi)
	{
		md = (lo + hi) / 2;
		int rem = a;
		for (int i = 0; i < md; i++)
		{
			if (p[i] > b[n-md + i])
				rem -= (p[i] - b[n-md + i]);
			if (rem < 0)
			{
				rem = -1;
				break;
			}
		}
		if (rem < 0)
			hi = md - 1;
		else
			lo = md + 1;
	}

	int r = hi;
	long long sm = 0;
	for (int i = 0; i < r; i++)
	{
		sm += p[i];
	}
	sm -= a;
	if (sm < 0)
		sm = 0;
	printf("%d %lld\n", r, sm);
}
