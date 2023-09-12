class Solution {
public:
unordered_map<string, unordered_map<string, double>> graph;

    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double quotient = values[i];

            // Add the edge: dividend -> divisor with weight quotient
            graph[dividend][divisor] = quotient;

            // Add the edge: divisor -> dividend with weight 1/quotient
            graph[divisor][dividend] = 1.0 / quotient;
        }
    }

    double dfs(string start, string end, unordered_set<string>& visited) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1.0;

        if (start == end)
            return 1.0;

        visited.insert(start);
        for (auto neighbor : graph[start]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double result = dfs(neighbor.first, end, visited);
                if (result != -1.0)
                    return result * neighbor.second;
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         buildGraph(equations, values);

        vector<double> results;
        for (auto query : queries) {
            string dividend = query[0];
            string divisor = query[1];
            unordered_set<string> visited;
            double result = dfs(dividend, divisor, visited);
            results.push_back(result);
        }

        return results;
        
    }
};