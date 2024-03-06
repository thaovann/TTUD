#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, u, v, k;
	int Q = 0;
	cin >> n;

	vector<int> A;

	A.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		cout << A[i];
	}


	cin >> m;

	vector<pair<int, int>> B(m);

	// Nhập giá trị cho vector B
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		B[i] = make_pair(u, v);
		cout << B[i].first << " " << B[i].second << endl;
	}

	// tạo mảng M[i][j] là giá trị nhỏ nhất chạy từ j đến j + 2^i
	// tạo mảng M[i][j] là giá trị nhỏ nhất chạy từ j đến j + 2^i
	int maxJ = floor(log2(n));
	vector<vector<int>> M(maxJ + 1, vector<int>(n));

	for (int i = 0; i < n; i++)
		M[0][i] = i;

	for (int j = 1; (1 << j) <= n; j++)
	{
		for (int i = 0; i + (1 << j) - 1 < n; i++)
		{
			if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]])
				M[j][i] = M[j - 1][i];
			else
				M[j][i] = M[j - 1][i + (1 << (j - 1))];
		}
	}

	for (int i = 0; i < m; i++)
	{
		k = floor(log2(B[i].second - B[i].first + 1));
		if (A[M[k][B[i].first]] < A[M[k][B[i].second - (1 << k) + 1]])
			Q += A[M[k][B[i].first]];
		else
			Q += A[M[k][B[i].second - (1 << k) + 1]];
	}

	cout << Q;
	return 0;
}
