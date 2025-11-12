#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Node {
	public:
		vector<Node*> parents;
		vector<Node*> children;
		bool marked;

		Node() {
			marked = false;
		}

		void mark_parents() {
			if (!marked) {
				marked = true;
				for (auto node : parents) {
					if (!node->marked) {
						node->mark_parents();
					}
				}
			}
		}

		void mark_children() {
			if (!marked) {
				marked = true;
				for (auto node : children) {
					if (!node->marked) {
						node->mark();
					}
				}
			}
		}

		void mark() {
			mark_parents();
			mark_children();
		}
};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<int> data;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		data.push_back(num);
	}

	vector<vector<int>> not_dp;
	not_dp.resize(n + 1, vector<int>(n, -1));

	vector<vector<Node*>> nodes;
	nodes.resize(n + 1, vector<Node*>(n));

	for (int l = 1; l <= n; l++) {
		for (int i = 0; i + l <= n; i++) {
			nodes[l][i] = new Node;
		}
	}

	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int l = 1; i + l <= n; l++) {
			temp ^= data[i + l - 1];
			not_dp[l][i] = temp;
			if (l > 1) {
				nodes[l - 1][i]->parents.push_back(nodes[l][i]);
				nodes[l - 1][i + 1]->parents.push_back(nodes[l][i]);
				nodes[l][i]->children.push_back(nodes[l - 1][i]);
				nodes[l][i]->children.push_back(nodes[l - 1][i + 1]);
			}
		}
	}

	int count = 0;
	int total_len = 0;

	for (int l = 1; l <= n; l++) {
		for (int i = 0; i + l <= n; i++) {
			if (not_dp[l][i] == k) {
				if (!nodes[l][i]->marked) {
					nodes[l][i]->mark();
					count++;
					total_len += l;
				}
			}
			if (total_len == n) {
				break;
			}
			if (total_len > n) {
				count--;
			}
		}
		if (total_len == n) {
			break;
		}
		if (total_len > n) {
			break;
		}
	}

	cout << count << endl;

	return 0;
}
