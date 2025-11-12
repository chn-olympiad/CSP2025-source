#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	int arr[nm];
	for(int i=1;i<=nm;i++)
		cin>>arr[i];
	sort(arr+n+m,arr+n+m+1);
	for(int i=1;i<=nm;i++)
		cout<<arr[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
