class Manacher {
    public:
    vector <int> p;
    
    Manacher(string &t) {
        string s;
        for(auto c: t) {
            s.push_back('#');
            s.push_back(c);
        } s.push_back('#');
        
        int n = s.size(),
            l = 0, r = 0;
        p.resize(n);
        for(int i = 1; i < n - 1; i++) {
            p[i] = max(0ll, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) p[i]++;
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
    }
    
    bool isPalindrome(int l, int r) {
        int size = (r - l + 1);
        return p[l + r + 1] >= size;
    }
};