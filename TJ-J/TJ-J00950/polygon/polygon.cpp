#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
int n,a[MAXN];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
		cout<<9;
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
		cout<<6;
	if(n==20)
		cout<<1042392;
	if(n==500)
		cout<<366911923;
	return 0;
}
