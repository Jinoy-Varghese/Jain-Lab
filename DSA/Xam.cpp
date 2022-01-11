// C++ program of the above approach
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;
// BSF Memoization
typedef tuple<int, int, int> tupl;

// Function to implement BFS
int findCheapestPrice(int cities,
					vector<vector<int> >& flights,
					int src, int dst, int stops)
{
	unordered_map<int,
				vector<pair<int, int> > >
		adjList;

	// Traverse flight[][]
	for (auto flight : flights) {

		// Create Adjacency Matrix
		adjList[flight[0]].push_back(
			{ flight[1], flight[2] });
	}

	// < city, distancefromsource > pair
	queue<pair<int, int> >
		q;
	q.push({ src, 0 });

	// Store the Result
	int srcDist = INT_MAX;

	// Traversing the Matrix
	while (!q.empty() && stops-- >= 0) {

		int qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			pair<int, int> curr = q.front();
			q.pop();

			for (auto next : adjList[curr.first]) {

				// If source distance is already
				// least the skip this iteration
				if (srcDist < curr.second
								+ next.second)
					continue;

				q.push({ next.first,
						curr.second
							+ next.second });

				if (dst == next.first) {
					srcDist = min(
						srcDist, curr.second
									+ next.second);
				}
			}
		}
	}

	// Returning the Answer
	return srcDist == INT_MAX ? -1 : srcDist;
}

// Driver Code
int main()
{
	vector<vector<int> > flights
		= { { 4, 1, 1 }, { 1, 2, 3 }, { 0, 3, 2 }, { 0, 4, 10 }, { 3, 1, 1 }, { 1, 4, 3 } };

	int stops = 2;
	int totalCities = 5;

	int sourceCity = 0;
	int destCity = 4;

	long ans = findCheapestPrice(
		totalCities, flights,
		sourceCity, destCity,
		stops);
	cout << ans;
	return 0;
}
