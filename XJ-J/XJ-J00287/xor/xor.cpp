#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[1000];
	int max=a[0];
	for(int i=0;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;++i)
	{
		if(max<a[i])
			max=a[i];
		else
			max=a[0];
	}	
	cout<<max;
	fclose(stdin);
	fclose(stdout);
}
