#include <vector>

using namespace std;

class SegmentTree {
    vector<long long> tree_sum;
    vector<long long> tree_sum_sq;
    vector<long long> lazy;
    int n;
    long long MOD = 1e9 + 7;

public:
    SegmentTree(int n) {
        this->n = n;
        tree_sum.assign(4 * n + 1, 0);
        tree_sum_sq.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }

    void apply(int node, long long length, long long val) {
        // (old_sum + val)^2 = old_sum^2 + 2 * val * old_sum + val^2
        tree_sum_sq[node] = (tree_sum_sq[node] + 
                             2 * val * tree_sum[node] % MOD + 
                             val * val % MOD * length % MOD) % MOD;
                             
        tree_sum[node] = (tree_sum[node] + val * length % MOD) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push_down(int node, int left, int right) {
        if (lazy[node] != 0) {
            int mid = left + (right - left) / 2;
            long long val = lazy[node];
            
            apply(2 * node, mid - left + 1, val);
            apply(2 * node + 1, right - mid, val);
            
            lazy[node] = 0;
        }
    }

    void update(int node, int left, int right, int ql, int qr, long long val) {
        if (ql <= left && right <= qr) {
            apply(node, right - left + 1, val);
            return;
        }

        push_down(node, left, right);
        int mid = left + (right - left) / 2;

        if (ql <= mid) {
            update(2 * node, left, mid, ql, qr, val);
        }
        if (qr > mid) {
            update(2 * node + 1, mid + 1, right, ql, qr, val);
        }

        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sum_sq[node] = (tree_sum_sq[2 * node] + tree_sum_sq[2 * node + 1]) % MOD;
    }
    
    long long get_root_sum_sq() {
        return tree_sum_sq[1];
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);
        
       
        vector<int> last_seen(100005, -1); 
        
        long long total_ans = 0;
        long long MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            
            int start_idx = last_seen[x] + 1;
            
           
            st.update(1, 1, n, start_idx + 1, i + 1, 1);
           
            total_ans = (total_ans + st.get_root_sum_sq()) % MOD;
            
           
            last_seen[x] = i;
        }

        return total_ans;
    }
};