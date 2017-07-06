#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>

#include "heuristics.h"


//http://www.drdobbs.com/windows/user-defined-hash-functions-for-unordere/231600210?pgno=4
namespace std {
    template <>
        class hash<std::pair<int, int>>{
        public :
            size_t operator()(const pair<int,int>& p ) const
            {
                return hash<int>()(p.first) ^ hash<int>()(p.second);
            }
    };
};



template<typename T, typename U>
class Graph{

	std::unordered_map<T, std::vector<std::pair<T, U>>> edges;
	/*
	 *without custom hash function, pair cannot be a key of unordered_map/set
	 * https://groups.google.com/forum/#!topic/comp.lang.c++.moderated/RMLdM6QpzHA
	 * I can also use an ordered map - slow O(logn)
	 * But the whole code will need revision :(
	 */

public:

	void add_edge(const T& source, const T& destination, U weight = 1)
	{
		edges[source].push_back({destination, weight});
	}

	bool Astar(const T&, const T&, std::unordered_map<T, T>&, std::unordered_map<T, U>&);	

};

   



template<typename T, typename U>
bool Graph<T,U>::Astar
	(const T& source,
	 const T& destination,
	 std::unordered_map<T, T>& parent,
	 std::unordered_map<T, U>& cost)
{
	std::priority_queue <std::pair<U, T>> frontier;
	std::unordered_map<T, bool> visit;

	auto h = Manhattan(source, destination);
	frontier.push({h, source});

	parent[source] = source;
	cost[source] = 0;

	 

	while(!frontier.empty()){
		auto current  = frontier.top();
		frontier.pop();

		if(current.second == destination)
			break;
		if(visit[current.second])
			continue;

		visit[current.second] = true;

		for(auto& next : edges[current.second])
		{
			auto tentative_cost = cost[current.second] + next.second;
			if(!cost.count(next.first) or tentative_cost<cost[next.first])
			{
				cost[next.first] = tentative_cost;
				h = Manhattan(next.first, destination); //change Manhattan to Euclidean or Diagonal
 				frontier.push({h + tentative_cost, next.first});
				parent[next.first] = current.second;
			} 
		}
	}

	return cost.count(destination);
}

int main()
{
	//https://www.hackerrank.com/challenges/pacman-astar
	//http://ideone.com/yJcS1K
	return 0;
}
