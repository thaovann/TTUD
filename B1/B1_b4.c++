#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
	stack<int> s;
	heights.push_back(0); // Add a dummy element to handle the end of the heights vector
	int maxArea = 0;
	for (int i = 0; i < heights.size(); ++i)
	{
		while (!s.empty() && heights[i] < heights[s.top()])
		{
			int height = heights[s.top()];
			s.pop();
			int width = s.empty() ? i : (i - s.top() - 1);
			maxArea = max(maxArea, height * width);
		}
		s.push(i);
	}
	return maxArea;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> A(n, vector<int>(m));
	vector<int> heights(m, 0);
	int maxArea = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> A[i][j];
			if (A[i][j] == 0)
			{
				heights[j] = 0; // Reset height if current cell is 0
			}
			else
			{
				heights[j]++; // Increment height if current cell is 1
			}
		}
		maxArea = max(maxArea, largestRectangleArea(heights)); // Update max area for each row
	}

	cout << maxArea << endl;

	return 0;
}
