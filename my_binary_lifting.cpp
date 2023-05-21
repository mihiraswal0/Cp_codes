vector<vector<int>>dp(2e5 + 5, vector<int>(31));
	function<void(int , int )>bf = [&](int node, int par) {
		dp[node][0] = par;
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
				bf(child, node);
		}

	};
	function<int(int, int)>query = [&](int node, int k)
	{
		for (int i = 30; i >= 0; i--)
		{

			if (node == -1)
				break;
			if ((1ll << i)&k)
			{
				node = dp[node][i];

			}
		}
		return node;
	};
