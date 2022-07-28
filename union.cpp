vector<int>parent(1e5 + 4);
vector<int>rankk(1e5 + 4);
int findP(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = findP(parent[a]);
}
void unionn(int a, int b) {
	a = findP(a);
	b = findP(b);
	// parent[a] = b;
	if (a != b) {
		if (rankk[a] < rankk[b])
			parent[a] = b, rankk[b] += a;
		else
			parent[b] = a, rankk[a] += b;
	}
