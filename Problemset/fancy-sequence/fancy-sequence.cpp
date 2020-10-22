
// @Title: 奇妙序列 (Fancy Sequence)
// @Author: 554216885@qq.com
// @Date: 2020-10-22 08:42:22
// @Runtime: 1676 ms
// @Memory: 325.9 MB

#include <bits/stdc++.h>
using namespace std;


class Fancy {
public:
    using ll = long long;

    static const int N = 1e5 + 10;
    static const int p = 1e9 + 7;
    int tot;
    int n, m;
    struct node
    {
        int l, r;
        ll sum, add, mul;
        node() {l = r = sum = add = 0; mul = 1;};
    }tree[N * 4];

    inline int ls(int cur) 
    {
        return cur << 1;
    }

    inline int rs (int cur)
    {
        return (cur << 1) | 1;
    }

    inline void push_up(int cur)
    {
        tree[cur].sum = (tree[ls(cur)].sum + tree[rs(cur)].sum) % p;
    }

    inline void push_down(int cur)
    {
        if (tree[cur].mul != 1 or tree[cur].add != 0) {
            tree[ls(cur)].sum = (tree[ls(cur)].sum * tree[cur].mul + (tree[ls(cur)].r - tree[ls(cur)].l + 1) * tree[cur].add) % p;
            tree[rs(cur)].sum = (tree[rs(cur)].sum * tree[cur].mul + (tree[rs(cur)].r - tree[rs(cur)].l + 1) * tree[cur].add) % p;
            tree[ls(cur)].mul = tree[ls(cur)].mul * tree[cur].mul % p;
            tree[rs(cur)].mul = tree[rs(cur)].mul * tree[cur].mul % p;
            tree[ls(cur)].add = (tree[ls(cur)].add * tree[cur].mul + tree[cur].add) % p;
            tree[rs(cur)].add = (tree[rs(cur)].add * tree[cur].mul + tree[cur].add) % p;
            tree[cur].add = 0;
            tree[cur].mul = 1;
        }
    }


    void build(int cur, int l, int r) 
    {
        if (l == r) {
            tree[cur].l = l;
            tree[cur].r = r;
            return;
        }
        int mid = (l + r) >> 1;
        tree[cur].l = l; tree[cur].r = r;
        build(ls(cur), l, mid);
        build(rs(cur), mid + 1, r);
        push_up(cur);
    }

    void add(int cur, int l, int r, int v)
    {
        if (tree[cur].l == l and tree[cur].r == r){
            tree[cur].sum = (tree[cur].sum + (r - l + 1) * v) %p;
            tree[cur].add = (tree[cur].add + v) % p;
            return;
        }
        push_down(cur);
        //继续往下
        //更新接下来的区间，保证他们是最新的
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (r <= mid) {
            add(ls(cur), l, r, v);
        }
        else if (l > mid) {
            add(rs(cur), l, r, v);
        }
        else {
            add(ls(cur), l, mid, v);
            add(rs(cur), mid + 1, r, v);
        }
        //所有区间都从自己的子区间获取值的更新
        push_up(cur);
    }

    void mul(int cur, int l, int r, int v)
    {
        if (tree[cur].l == l and tree[cur].r == r){
            tree[cur].sum = (tree[cur].sum * v) % p;
            tree[cur].mul = (tree[cur].mul * v) % p;
            tree[cur].add = (tree[cur].add * v) % p;
            return;
        }
        push_down(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (r <= mid) {
            mul(ls(cur), l, r, v);
        }
        else if (l > mid) {
            mul(rs(cur), l, r, v);
        }
        else {
            mul(ls(cur), l, mid, v);
            mul(rs(cur), mid + 1, r, v);
        }
        //所有区间都从自己的子区间获取值的更新
        push_up(cur);
    }

    ll query(int cur, int l, int r)
    {
        if (tree[cur].l == l and tree[cur].r == r){
            return tree[cur].sum;
        }
        push_down(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (r <= mid) {
            return query(ls(cur), l, r);
        }
        else if (l > mid) {
            return query(rs(cur), l, r);
        }
        else {
            return (query(ls(cur), l, mid) + query(rs(cur), mid + 1, r)) % p;
        }
        //没有更新操作，所以不需要push_up
    }

    Fancy() {
        tot = 0;
        build(1, 1, N);
    }
    
    void append(int val) {
        ++tot;
        add(1, tot, tot, val);
    }
    
    void addAll(int inc) {
        add(1, 1, tot, inc);
    }
    
    void multAll(int m) {
        mul(1, 1, tot, m);
    }
    
    int getIndex(int idx) {
        if (idx > tot - 1)
            return -1;
        return query(1, idx + 1, idx + 1);
    }
};

