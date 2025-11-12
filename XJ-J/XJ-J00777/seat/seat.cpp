#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0,r=0;
	int a[100];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	for(int j=1;j<=n*m;j++)
	{
		if(a[j]>a[j+1])
		{
			sort(a,a+1);
		}
	}
	
	for(int i=1;i<=n*m;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
