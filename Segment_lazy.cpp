vector<int> seg;
vector<int>lazy;

void build(int ind, int low, int high, int arr[]) {
	if (low == high) {
		seg[ind] = arr[low];
		return;
	}

	int mid = (low + high) / 2;
	build(2 * ind + 1, low, mid, arr);
	build(2 * ind + 2, mid + 1, high, arr);
	seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int querySum(int ind, int low, int high, int l, int r) {
		if(lazy[ind]!=0)
	{
		seg[ind]+=(high-low+1)*lazy[ind];
		if(low!=high)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}

	// no overlap
	// l r low high or low high l r

	if (r < low || high < l ||low>high) return 0;

	// complete overlap
	// [l low high r]
	if (low >= l && high <= r) return seg[ind];

	int mid = (low + high) >> 1;
	int left = querySum(2 * ind + 1, low, mid, l, r);
	int right = querySum(2 * ind + 2, mid + 1, high, l, r);
	return (left+ right);
}
void rangeupdate(int ind, int low, int high, int l,int r, int val) {
	if(lazy[ind]!=0)
	{
		seg[ind]+=(high-low+1)*lazy[ind];
		if(low!=high)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}
	if(r<low ||l>high ||low>high)
		return ;
	if(low>=l && high <=r)
	{
		seg[ind]+=(high-low+1)*val;
		if(low!=high)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		return;
	}
	int mid=(low+high)>>1;
	rangeupdate(2*ind+1,low,mid,l,r,val);
	rangeupdate(2*ind+2,mid+1,high,l,r,val);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}
