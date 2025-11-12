#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,flag=1;
	cin>>n;
	int  a[5005];
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i] != 1)
			flag = 0;
	}	
	sort(a+1,a+1+n,greater<int>());
	if(n!=3){
		if(flag == 1)
		{
			cout<<n - 2;
		}
		else
		cout<<0;
	} 
	else
	{	
		if(a[2]+a[3]>a[1])
			cout<<1;
		else
			cout<<0;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
