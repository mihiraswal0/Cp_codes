struct BinaryLifting {
	int n;
	int maxLog;
	ll maxRequirement;
	vector<vector<int>> parent;

	BinaryLifting(int n1, vector<vector<int>>&edges, ll requirement, int root) {
		n = n1;
		parent.resize(n);
		maxLog = log2(requirement + 1);
		maxRequirement = requirement;
		for (int i = 0; i < n; i++) {
			parent[i].resize(maxLog + 1);
			for (int j = 0; j <= maxLog; j++) {
				parent[i][j] = -1;
			}
		}
		fillParentTable(root, edges);

	}
	void fillParentTable(int root, vector<vector<int>> &edges) {
		vector<bool> visited(n);
		dfsBinaryLifting(root, edges, visited);
		int intermediate = -1;
		for (int i = 1; i <= maxLog; i++) {
			for (int j = 0; j < n; j++) {
				intermediate = parent[j][i - 1];
				if (intermediate != -1) {
					parent[j][i] = parent[intermediate][i - 1];
				}
			}
		}
	}
	void dfsBinaryLifting(int root, vector<vector<int>> &edges, vector<bool> &visited) {
		visited[root] = true;
		for (auto i : edges[root]) {
			if (!visited[i]) {
				parent[i][0] = root;
				dfsBinaryLifting(i, edges, visited);
			}
		}
	}

	int kthParent(int x, int k) {
		for (int i = 0; i <= maxLog; i++) {
			if ((k >> i) & 1) {
				if (x == -1)
					return x;
				x = parent[x][i];
			}
		}
		return x;
	}

};

struct LCA {
	int n;
	vector<int> level;
	LCA(int n1, vector<vector<int>> &edges, int root) {
		n = n1;
		level.resize(n);
		dfsLCA(root, edges, -1);
	}
	void dfsLCA(int root, vector<vector<int>> &edges, int parent) {
		for (auto i : edges[root]) {
			if (i != parent) {
				level[i] = level[root] + 1;
				dfsLCA(i, edges, root);
			}
		}
	}
	int getLCA(int a, int b, BinaryLifting &bl_object) {
		if (level[a] > level[b]) {
			swap(a, b);
		}
		b = bl_object.kthParent(b, level[b] - level[a]);
		if (a == b)
			return a;
		for (int i = bl_object.maxLog; i >= 0; i--) {
			int parent1 = bl_object.parent[a][i];
			int parent2 = bl_object.parent[b][i];
			if (parent2 != parent1 && parent1 != -1 && parent2 != -1) {
				a = parent1;
				b = parent2;
			}
		}
		return bl_object.parent[a][0];
	}
};
