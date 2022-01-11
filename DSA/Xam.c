// C++ program for the above approach
#include <bits/stdc++.h>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> tupl;
long findCheapestPrice(int cities,
					vector<vector<int> >& flights,
					int src, int dst, int stops)
{
	// Adjacency Matrix
	vector<vector<pair<int, int> > > adjList(cities);

	// Traverse flight[][]
	for (auto flight : flights) {
		// Create Adjacency Matrix
		adjList[flight[0]].push_back(
			{ flight[1], flight[2] });
	}

	// Implementing Priority Queue
	priority_queue<tupl, vector<tupl>,
				greater<tupl> >
		pq;

	tupl t = make_tuple(0, src, stops);
	pq.push(t);

	// While PQ is not empty
	while (!pq.empty()) {
		tupl t = pq.top();
		pq.pop();

		if (src == dst)
			return 0;

		int cost = get<0>(t);
		int current = get<1>(t);
		int stop = get<2>(t);

		if (current == dst)

			// Return the Answer
			return cost;

		if (stop >= 0) {
			for (auto next : adjList[current]) {

				tupl t = make_tuple((cost
									+ next.second),
									next.first,
									stop - 1);
				pq.push(t);
			}
		}
	}
	return -1;
}

int main()
{
	// Input flight : {Source,
	// Destination, Cost}
	vector<vector<int> > flights
		= { { 4, 1, 1 }, { 1, 2, 3 }, { 0, 3, 2 }, { 0, 4, 10 }, { 3, 1, 1 }, { 1, 4, 3 } };

	// vec, n, stops, src, dst
	int stops = 2;
	int totalCities = 5;

	// Given source and destination
	int sourceCity = 0;
	int destCity = 4;

	// Function Call
	long ans = findCheapestPrice(
		totalCities, flights,
		sourceCity, destCity, stops);
	cout << ans;
	return 0;
}
