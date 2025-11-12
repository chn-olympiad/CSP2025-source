#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];	
	cout<<arr[n]+arr[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
