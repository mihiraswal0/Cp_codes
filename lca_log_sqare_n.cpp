vector<vector<int>>dp(2e5 + 5, vector<int>(31));
	vector<int>level(2e5 + 5);
	function<void(int , int, int)>bf = [&](int node, int par, int l) {
		dp[node][0] = par;
		level[node] = l;
		for (int i = 1; i < 31; i++)
		{
			if (dp[node][i - 1] != -1)
				dp[node][i] = dp[dp[node][i - 1]][i - 1];
			else
				dp[node][i] = -1;
		}
		for (auto child : ar[node])
		{
			if (child != par)
				bf(child, node, l + 1);
		}

	};
	function<int(int, int)>query = [&](int node, int k)
	{
		for (int i = 30; i >= 0; i--)
		{

			if (node == -1 || !k)
				break;
			if ((1ll << i)&k)
			{
				node = dp[node][i];

			}
		}
		return node;
	};
	function<int(int, int )>lca = [&](int u, int v)
	{
		if (level[u] < level[v])
			swap(u, v);
		u = query(u, level[u] - level[v]); //lift kia u ko v tk ab woh same level pe h
		int st = 0;
		int en = level[u];

		while (st < en)
		{
			int mid = (st + (en - st) / 2);
			int x1 = query(u, mid);
			int y1 = query(v, mid);
			if (x1 == y1)
				en = mid;
			else
				st = mid + 1;
		}
		return query(u, st);
	};
