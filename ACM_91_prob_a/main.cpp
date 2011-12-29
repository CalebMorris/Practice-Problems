#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void solve( int const& , set<pair<int,int> > const& );
void discover( vector<int> const& , set<pair<int,int> > const& , int& );

int end;
int main() {
	end = 0;
		
	while( cin >> end ) {
		int x = -1, y = -1;
		set< pair<int, int> > edges;
		while ( (cin >> x >> y) && x != 0 && y != 0 ) {
			edges.insert( pair<int,int>(x,y) );
			edges.insert( pair<int,int>(y,x) );
		}
		solve( end, edges );
	}

	return 0;
}

void solve( int const& end, set<pair<int,int> > const& edges ) {
	vector<int> current;
	int count = 0;
	current.push_back(1);
	set<pair<int,int> >::const_iterator it;
	for( it = edges.begin(); it != edges.end() && it->first != 1; ++it );
	for( ; it != edges.end() && it->first == 1; ++it ) {
		if( find( current.begin(), current.end(), it->second ) == current.end() ) {
			vector<int> carry(current);
			carry.push_back( it->second );
			discover( carry, edges, count );
		}
	}
	cout << "There are " << count << " routes from the firestation to streetcorner " << end << "." << endl;
}

void discover( vector<int> const& current, set<pair<int,int> > const& edges, int& count ) {
	set<pair<int,int> >::const_iterator it;
	int last = *current.rbegin();
	for( it = edges.begin(); it != edges.end() && it->first != last; ++it );
	for( ; it != edges.end() && it->first == last ; ++it ) {
		if( find( current.begin(), current.end(), it->second ) == current.end() ) {
			vector<int> carry(current);
			carry.push_back( it->second );
			discover( carry, edges, count );
		}
	}
	if( end == *current.rbegin() ) {
		++count;
		for( vector<int>::const_iterator cit = current.begin(); *cit != *current.rbegin(); ++cit ) {
			cout << *cit << "\t";
		}
		cout << *current.rbegin() << endl;
	}
}