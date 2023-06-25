struct bit_2d {
	vector<vector<int>>bit;
	int n, m;
	bit_2d(int nn, int mm)
	{
		n = nn;
		m = mm;
		bit.resize(n + 5, vector<int>(m + 5));
	}
	void update(int x, int y, int val)
	{

		for (; x <= n; x += (x & (-x))) {
			for (int i = y; i <= n; i += (i & (-i))) { bit[x][i] += val; }
		}
	}
	int query(int x, int y)
	{
		int ans = 0;
		for (int i = x; i; i -= (i & (-i))) {
			for (int j = y; j; j -= (j & (-j))) { ans += bit[i][j]; }
		}
		return ans;
	}
};
