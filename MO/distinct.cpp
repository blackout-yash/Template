int block;
class Data {
public:
    int l, r, ind;
    bool operator<(const Data &n) const {
        int block1 = l / block;
        int block2 = n.l / block;

        if (block1 == block2) return r < n.r;    
        return block1 < block2;
    }
};
    
class MO {
public:  
    int tempAns;
    vector <int> freq;
    vector <Data> queries;
    MO(int n, int max) {
        tempAns = 0;
        block = sqrt(n) + 1;
        freq.resize(max + 1);
    }

    void build(int q, vector <pair <int, int>> &query) {
        queries.resize(q);
        for(int i = 0; i < q; i++) {
            queries[i].l = query[i].first;
            queries[i].r = query[i].second;
            queries[i].ind = i;
        }
        sort(queries.begin(), queries.end());
    }

    void add(int i, vector <int> &arr) {
        freq[arr[i]]++;
        if(freq[arr[i]] == 1) tempAns++;           
    }

    void remove(int i, vector <int> &arr) {
        freq[arr[i]]--;
        if(freq[arr[i]] == 0) tempAns--;           
    }

    vector <int> MOAlgo(int q, vector <int> &arr) {
        int i = 0, j = -1;
        vector <int> ans(q);
        for (auto x : queries) {
            while (i > x.l) add(--i, arr);
            while (j < x.r) add(++j, arr);

            while (i < x.l) remove(i++, arr);
            while (j > x.r) remove(j--, arr);
            
            ans[x.ind] = tempAns;
        }
        return ans;
    }
};