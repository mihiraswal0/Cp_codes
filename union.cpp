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

 struct DSU
    {
  vector<int> parent, size;
  int comp;
  DSU(int n)
  {
    parent.resize(n); size.resize(n);
    for (int i = 0; i < n; ++i)
    {
      parent[i] = i;
      size[i] = 1;
    }
    comp = n;
  }

  int get(int x)
  {
    return (parent[x] == x) ? x : parent[x] = get(parent[x]);
  }

  bool join(int a, int b)
  {
    a = get(a);
    b = get(b);

    if (a == b) return false;

    if (size[a] < size[b]) swap(a, b);

    size[a] += size[b];
    parent[b] = a;
    comp--;
    return true;
  }
