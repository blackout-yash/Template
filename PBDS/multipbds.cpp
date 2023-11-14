#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > multipbds;

int main() {
	// Declaration
	multipbds A;


	// Inserting elements
	A.insert({1, 0});
	A.insert({10, 1});
	A.insert({2, 2});
	A.insert({7, 3});
	A.insert({2, 3});


	// A contains
	cout << "A = \n";
	for (auto i : A)
		cout << "{" << i.first << "," << i.second << "}" << endl;
	cout << endl;


	// finding kth element
	cout << "0th element: ";
	pair<int, int> p = *A.find_by_order(0);
	cout << "{" << p.first << "," << p.second << "}" << endl;
	cout << endl;


	// finding number of elements smaller than X
	cout << "No. of elems smaller than 3: " << A.order_of_key({3, 0}) << endl;
	cout << endl;


	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 2: ";
	p = *A.lower_bound({2, 0});
	cout << "{" << p.first << "," << p.second << "}" << endl;
	cout << endl;


	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 2: ";
	p = *A.upper_bound({2, INT_MAX});
	cout << "{" << p.first << "," << p.second << "}" << endl;
	cout << endl;


	// Remove elements
	A.erase(A.lower_bound({2, 0}));
	A.erase(*A.lower_bound({7, 0}));


	// A contains
	cout << "A = \n";
	for (auto i : A)
		cout << "{" << i.first << "," << i.second << "}" << endl;
	cout << endl;

}