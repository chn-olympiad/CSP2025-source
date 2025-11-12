#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt,sun,b,sum;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cnt){
			b=i;
			break;
		} 
	}
	sum=b/n;
	if(b%n>0) sum++;
	sun=b-(sum-1)*n;
	if(sum==1) sun=b;
	if(sum%2==0)  sun=n-sun+1;
	cout<<sum<<" "<<sun;
	return 0;
}
