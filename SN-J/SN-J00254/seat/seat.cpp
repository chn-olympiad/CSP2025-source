#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,me;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>me;
	for(int i=1;i<m*n;i++)cin>>a[i];
	a[m*n]=me;
	sort(a+1,a+n*m+1,cmp);
	int ans;
	for(int i=1;i<=n*m;i++)
		if(a[i]==me)
		{
			ans=i;
			break;
		}
	if(ans%(2*n)==0) cout<<ans/n<<" "<<1;
	else if(ans%n==0) cout<<ans/n<<" "<<m;
	else
	{
		if(ans%(2*n)>n) cout<<ans/n+1<<" "<<m+1-ans%n;
		else cout<<ans/n+1<<" "<<ans%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
