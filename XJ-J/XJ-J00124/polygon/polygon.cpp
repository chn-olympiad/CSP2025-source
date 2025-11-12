#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5005];
	int n,sum=0,s=0,i,max;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	max=a[n];
	for(i=1;i<=n;i++){
		sum+=a[i];
		if(sum>max*2) s++;
	}
	cout<<s;
	return 0;
} 
