struct BIT
{
    int n;
    vi bit;
    BIT(int N)
    {
        n = N;
        bit.assign(n + 1,0);
    }
    void update(int i,int v)
    {
        for (;i<=n;i += i & (-i))
            bit[i] = (bit[i] + v)%mod;
    }
    int query(int i)
    {
        int ret = 0;
        for (;i>0;i-= i & (-i))ret = (ret + bit[i])%mod;
        return ret;
    }
    
    void update(int l,int r,int v)
 
    //a[l] += v, a[l + 1] += v, ... a[n] += v,
    //a[r + 1] -= v,a[r + 2] -= v,a[n] -= v
    //=> a[l] to a[r] are all increased by +v
 
    {
        update(l,v);
        if (r != n)update(r + 1,-v);
    }
};
