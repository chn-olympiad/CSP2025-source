#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	cout<<arr[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
