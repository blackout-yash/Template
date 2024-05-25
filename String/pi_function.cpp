vector <int> compute_pi(string &str) {
  int n = str.size();
  vector <int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1]; 
    while (j > 0 && str[j] != str[i]) j = pi[j - 1];
    if (str[j] == str[i]) pi[i] = j + 1;
  }
  return pi;
}
 
vector <int> allOccurence(string &pat, string &text) {
    string s = pat + "$" + text;
    int n = pat.size(), m = text.size();
    vector <int> pi = compute_pi(s), ans;
    for (int i = n + 1; i <= n + m; i++) {
        if (pi[i] == n) {
            int curr = i - 2 * n;
            // Only non overlapping occurence
            if(ans.empty()) ans.push_back(curr);
            else if(curr - ans.back() >= n) ans.push_back(curr);

            // all occurence
            // ans.push_back(curr);
        }
    }
 
    return ans; 
}