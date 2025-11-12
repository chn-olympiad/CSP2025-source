#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	
	vector<int> scores(n * m);
	for(int i=0;i<n*m;i++){
		cin >> scores[i];
	}
	int rank=1;
	int c=(rank-1)/n+1;
	int r=(rank-1) %n+1;
	cout << c << " " << r;
	return 0;
} 
