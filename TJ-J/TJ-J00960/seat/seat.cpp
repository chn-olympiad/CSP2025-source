#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	int n,m;
	int maxn =0;
	int a[n*m];
	fot(int i =1;i<=m;i++)
	{
		for(int j=1;i<=n;i++)
		{
			cin >> a[j];
			if(a[j]>maxn) maxn = a[j];
		}
	}
	cout <<"1 2";
	
	return 0;
}
