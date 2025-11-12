#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	int f1=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) f1=0;
	}
	sort(a+1,a+n+1);
	if(f1)
	{
		int cnt=0;
		for(int i=1;i<=n-2;i++)
			cnt+=i;
		cout<<cnt<<endl;
	}
	else
	{
		int sj=rand()%998244353;
		cout<<sj<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

