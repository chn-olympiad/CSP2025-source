#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],rkr;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int tot=n*m;
	for(int i=1;i<=tot;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+1+tot,greater<int>());
	for(int i=1;i<=tot;i++)
	{
		if(a[i]==r)
		{
			rkr=i;
			break;
		}
	}
	int h=rkr%n;
	int l=rkr/n+(h?1:0);
	if(h==0)cout<<l<<" "<<(l&1?n:1);
	else if(l&1)cout<<l<<" "<<h;
	else cout<<l<<" "<<n-h+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
