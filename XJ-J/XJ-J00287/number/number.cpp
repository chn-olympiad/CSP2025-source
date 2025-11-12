#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
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
