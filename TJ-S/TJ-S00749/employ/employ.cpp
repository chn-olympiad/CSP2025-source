#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c[n];
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> c[i];
		sum += c[i];
	}
	cout << sum;
	return 0;
}
