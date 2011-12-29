#include <iostream>
#include <set>
#include <vector>

using namespace std;

class node {
	public:
		int value;
		bool visited;
		node(): value(0), visited(false){}	
		node( int inp ) : value(inp), visited(false){}

		void visit() { visited = true; }
};

void solve( int const& , set<pair<int,int> > const& );
void discover( vector<node> const& , set<pair<int,int> > const& , int& );

int end;
int main() {
	end = 0;
		
	while( cin >> end ) {
		int x = -1, y = -1;
		set< pair<int, int> > edges;
		while ( (cin >> x >> y) && x != 0 && y != 0 ) {
			if( x < y ) {
				edges.insert( pair<int,int>(x,y) );
			}
			else {
				edges.insert( pair<int,int>(y,x) );
			}
		}
		cout << end << endl;
		for ( set<pair<int,int> >::iterator it = edges.begin(); it != edges.end(); ++it ) {
			cout << it->first << " " << it ->second << endl;
		}
		solve( end, edges );
	}

	return 0;
}

void solve( int const& end, set<pair<int,int> > const& edges ) {
	vector<node> current;
	int count = 0;
	current.push_back(node(1));
	set<pair<int,int> >::const_iterator it;
	for( it = edges.begin(); it != edges.end() && it->first != 1; ++it );
	for( ; it != edges.end() && it->first == 1; ++it ) {
		vector<node> carry(current);
		carry.push_back( node( it->second ) );
		discover( carry, edges, count );
	}
	cout << "There are " << count << " routes from the firestation to streetcorner " << end << "." << endl;
}

void discover( vector<node> const& current, set<pair<int,int> > const& edges, int& count ) {
	set<pair<int,int> >::const_iterator it;
	int last = current.rbegin()->value;
	for( it = edges.begin(); it != edges.end() && it->first != last; ++it );
	for( ; it != edges.end() && it->first == last ; ++it ) {
		vector<node> carry(current);
		carry.push_back( node( it->second ) );
		discover( carry, edges, count );
	}
	/* Causing loop. Need to add visited conditions
	for( it = edges.begin(); it != edges.end() && it->second != last; ++it );
	for( ; it != edges.end() && it->second == last ; ++it ) {
		vector<node> carry(current);
		carry.push_back( node( it->first ) );
		discover( carry, edges, count );
	}
	*/
	if( end == (current.rbegin())->value ) {
		++count;
		for( vector<node>::const_iterator cit = current.begin(); cit != (current.end()-1); ++cit ) {
			cout << cit->value << "\t";
		}
		cout << (current.rbegin())->value << endl;
	}
}