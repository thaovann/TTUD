#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct Point
{
	int x, y;
	
	int steps;
};

int main()
{
	int n, m, r, c;
	cin >> n >> m >> r >> c;

	vector<vector<int>> maze(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];
		}
	}

	queue<Point> q;
	q.push({r - 1, c - 1, 0});
	visited[r - 1][c - 1] = true;

	while (!q.empty())
	{
		Point current = q.front();
		q.pop();

		if (current.x == 0 || current.x == n - 1 || current.y == 0 || current.y == m - 1)
		{
			cout << current.steps + 1 << endl;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int next_x = current.x + dx[i];
			int next_y = current.y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && maze[next_x][next_y] == 0 && !visited[next_x][next_y])
			{
				q.push({next_x, next_y, current.steps + 1});
				visited[next_x][next_y] = true;
			}
		}
	}

	cout << -1 << endl; // No exit found
	return 0;
}
