#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+5;
int n, sum, t;
vector<int> a[4];

int main()
{
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	
	cin >> t;
	for(int i=1; i<=t; i++)
	{
		cin >> n;
		bool f1=0, f2=0;
		vector<int> a[4];
		sum = 0;
		for(int j=0; j<n; j++)
		{
			int k;
			cin >> k;
			a[1].push_back(k);
			cin >> k;
			a[2].push_back(k);
			cin >> k;
			a[3].push_back(k);
			if(a[2][j] == 0 && a[3][j] == 0)
			{
				f1 = 1;
			}
			else if(a[3][j] == 0)
			{
				f2 = 1;
			}
		}
		if(f1)
		{
			sort(a[1].begin(), a[1].end());
			for(int k=n-1; k>=(n-1)/2+1; k--)
			{
				sum += a[1][k];
			}
			cout << sum << endl;
		}
		else if(f2)
		{
			
			sort(a[2].begin(), a[2].end());
			sort(a[1].begin(), a[1].end());
			for(int k=n-1; k>=(n-1)/2+1; k--)
			{
				sum += a[2][k];
				sum += a[3][k];
			}
			cout << sum << endl;
		}
	}
	
	
	return 0;
}
