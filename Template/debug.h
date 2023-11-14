#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
#define int long long

#define debug(x) cout << #x << " => "; pprintt(x); cout << "\n";
template <typename T> void pprintt(T t) {cout << t;}
template <class T, class V> void pprintt(pair <T, V> p);
template <class T> void pprintt(vector <T> v);
template <class T> void pprintt(set <T> v);
template <class T, class V> void pprintt(map <T, V> v);
template <class T> void pprintt(multiset <T> v);
template <class T, class V> void pprintt(pair <T, V> p) {cout << "{"; pprintt(p.first); cout << ","; pprintt(p.second); cout << "}";}
template <class T> void pprintt(vector <T> v) {cout << "[ "; for (T i : v) {pprintt(i); cout << " ";} cout << "]\n";}
template <class T> void pprintt(set <T> v) {cout << "[ "; for (T i : v) {pprintt(i); cout << " ";} cout << "]";}
template <class T> void pprintt(queue <T> v) {cout << "[ "; while (v.size()) {pprintt(v.front()); cout << " "; v.pop();} cout << "]";}
template <class T> void pprintt(priority_queue <T> v) {cout << "[ "; while (v.size()) {pprintt(v.top()); cout << " "; v.pop();} cout << "]";}
template <class T> void pprintt(stack <T> v) {cout << "[ "; while (v.size()) {pprintt(v.top()); cout << " "; v.pop();} cout << "]";}
template <class T> void pprintt(multiset <T> v) {cout << "[ "; for (T i : v) {pprintt(i); cout << " ";} cout << "]";}
template <class T, class V> void pprintt(map <T, V> v) {cout << "[ "; for (auto i : v) {pprintt(i); cout << " ";} cout << "]";}