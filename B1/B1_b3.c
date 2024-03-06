#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int main()
{
	int n, m, u, v, k;
	int Q = 0;
	scanf("%d", &n);
	int **M = (int **)malloc(30 * sizeof(int *));
	for (int i = 0; i < 30; ++i)
	{
		M[i] = (int *)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &M[0][i]);
	}

	for (int j = 1; (1 << j) <= n; ++j)
	{
		for (int i = 0; i + (1 << j) - 1 < n; ++i)
		{
			if (M[j - 1][i] < M[j - 1][i + (1 << (j - 1))])
				M[j][i] = M[j - 1][i];
			else
				M[j][i] = M[j - 1][i + (1 << (j - 1))];
		}
	}

	scanf("%d", &m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		k = floor(log2(v - u + 1));
		if (M[k][u] < M[k][v - (1 << k) + 1])
			Q += M[k][u];
		else
			Q += M[k][v - (1 << k) + 1];
	}

	printf("%d\n", Q);

	for (int i = 0; i < 30; ++i)
	{
		free(M[i]);
	}
	free(M);

	return 0;
}
