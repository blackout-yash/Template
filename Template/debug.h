#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>

#define int long long
using namespace std;
// using namespace __gnu_pbds;

// typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef tree <pair <int, int>, null_type, less <pair <int, int>>, rb_tree_tag, tree_order_statistics_node_update> multipbds;

#define debug(x) cerr << #x << " => "; pprintt(x); cerr << "\n";
template <typename T> void pprintt(T t) {cerr << t;}
template <class T, class V> void pprintt(pair <T, V> p);
template <class T> void pprintt(vector <T> v);
template <class T> void pprintt(set <T> v);
template <class T, class V> void pprintt(map <T, V> v);
template <class T> void pprintt(multiset <T> v);
template <class T, class V> void pprintt(pair <T, V> p) {cerr << "{"; pprintt(p.first); cerr << ","; pprintt(p.second); cerr << "}";}
template <class T> void pprintt(vector <T> v) {cerr << "[ "; for (T i : v) {pprintt(i); cerr << " ";} cerr << "]\n";}
template <class T> void pprintt(set <T> v) {cerr << "[ "; for (T i : v) {pprintt(i); cerr << " ";} cerr << "]";}
template <class T> void pprintt(queue <T> v) {cerr << "[ "; while (v.size()) {pprintt(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void pprintt(priority_queue <T> v) {cerr << "[ "; while (v.size()) {pprintt(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void pprintt(stack <T> v) {cerr << "[ "; while (v.size()) {pprintt(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void pprintt(multiset <T> v) {cerr << "[ "; for (T i : v) {pprintt(i); cerr << " ";} cerr << "]";}
template <class T, class V> void pprintt(map <T, V> v) {cerr << "[ "; for (auto i : v) {pprintt(i); cerr << " ";} cerr << "]";}

// void pprintt(pbds v) {cerr << "[ "; for (auto i : v) {pprintt(i); cerr << " ";} cerr << "]";}
// void pprintt(multipbds v) {cerr << "[ "; for (auto i : v) {pprintt(i); cerr << " ";} cerr << "]";}