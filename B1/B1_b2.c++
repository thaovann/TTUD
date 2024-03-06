#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;  // lưu bản đồ của mê cung
map<pair<int, int>, int> M;  // lưu thứ tự duyệt đến theo chiều rộng
queue<pair<int, int>> Q;    // lưu danh sách các tọa độ của vị trí chuẩn bị duyệt
int step; 
int n, m;

bool is_valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < n && j < m;
}

bool BFS(int i, int j)
{
	if (!is_valid(i, j))
	{
		step = -1;
		return false;
	}

	pair<int, int> p;
	if (is_valid(i - 1, j) && A[i - 1][j] == 0 && M.find({i - 1, j}) == M.end())
	{
		p.first = i - 1;
		p.second = j;
		Q.push(p);
		M[{i - 1, j}] = M[{i, j}] + 1;
		if (i - 1 == 0)
			return false;
	}

	if (is_valid(i + 1, j) && A[i + 1][j] == 0 && M.find({i + 1, j}) == M.end())
	{
		p.first = i + 1;
		p.second = j;
		Q.push(p);
		M[{i + 1, j}] = M[{i, j}] + 1;
		if (i + 1 == n - 1)
			return false;
	}

	if (is_valid(i, j - 1) && A[i][j - 1] == 0 && M.find({i, j - 1}) == M.end())
	{
		p.first = i;
		p.second = j - 1;
		Q.push(p);
		M[{i, j - 1}] = M[{i, j}] + 1;
		if (j - 1 == 0)
			return false;
	}

	if (is_valid(i, j + 1) && A[i][j + 1] == 0 && M.find({i, j + 1}) == M.end())
	{
		p.first = i;
		p.second = j + 1;
		Q.push(p);
		M[{i, j + 1}] = M[{i, j}] + 1;
		if (j + 1 == m - 1)
			return false;
	}

	return true;
}

int main()
{
	int r, c;

	//input dữ liệu
	cin >> n >> m >> r >> c;

	A.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}

	M[{r-1, c-1}] = 1;
	Q.push({r-1,c-1});

	while (!Q.empty())
	{
		pair<int, int> current = Q.front();
		Q.pop();
		int i = current.first;
		int j = current.second;
		if (!BFS(i, j))
		{
			cout << M[{i, j}] << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}
