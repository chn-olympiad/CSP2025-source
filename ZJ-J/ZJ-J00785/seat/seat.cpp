#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,x,ans=1;
	scanf("%d%d%d",&n,&m,&a);
	x=a;
	for(int i=1;i<n*m;i++)
	{
		int b;
		scanf("%d",&b);
		if(b>a)
			ans++;
	}
	cout<<int((ans+n-1)/n)<<" ";
	if(int((ans+n-1)/n)%2==0)
		cout<<n-(ans-1)%n;
	else
		cout<<(ans-1)%n+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}