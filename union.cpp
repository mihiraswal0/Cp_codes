 vector<int>parent;
    vector<int>rankk;
int findP(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = findP(parent[a]);
}
void unionn(int a, int b) {
	a = findP(a);
	b = findP(b);
if (a != b) {
		if (rankk[a] < rankk[b])
			parent[a] = b;
		else if(rankk[b]<rankk[a])
			parent[b] = a;
        else
            parent[a]=b,rankk[b]++;
}}
