class node {
public:
	ll maxsum, mprefix, msuffix, sum;
	node()
	{
		maxsum = 0;
		mprefix = 0;
		msuffix = 0;
		sum = 0;
	}
};
class SEG {
public:
	vector<node> seg;
	SEG(int n) {
		seg.resize(4 * n);
	}

	node combine(node left, node right)
	{
		node cur;
		cur.sum = left.sum + right.sum;
		cur.mprefix = max(left.mprefix, left.sum + right.mprefix);
		cur.msuffix = max(right.msuffix, right.sum + left.msuffix);
		cur.maxsum = max({left.maxsum, right.maxsum, left.msuffix + right.mprefix});
		return cur;

	}
	void build(int ind, int low, int high, vector<ll>&arr) {
		if (low == high) {
			seg[ind].sum = arr[low];
			seg[ind].maxsum = max(0ll, arr[low]);
			seg[ind].mprefix = max(0ll, arr[low]);
			seg[ind].msuffix = max(0ll, arr[low]);
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);

	}
	node query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		node esi;
		if (r < low || high < l) return  esi;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		node left = query(2 * ind + 1, low, mid, l, r);
		node right = query(2 * ind + 2, mid + 1, high, l, r);
		return combine(left, right);
	}

	void update(int ind, int low, int high, int i, ll val) {
		if (low == high) {
			seg[ind].sum = val;
			seg[ind].maxsum = max(0ll, val);
			seg[ind].mprefix = max(0ll, val);
			seg[ind].msuffix = max(0ll, val);
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = combine(seg[2 * ind + 1] , seg[2 * ind + 2]);

	}

};
