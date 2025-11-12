#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],k;
bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>a[i*n+j];
			b[i*n+j]=a[i*n+j];
		}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
		if(b[0]==a[i])k=i+1;
	if(k%n==0&&(k/n)%2==0)printf("%d 1",k/n);
	if(k%n==0&&(k/n)%2==1)printf("%d %d",k/n,n);
	if(k%n!=0&&(k/n)%2==0)printf("%d %d",k/n+1,k%n);
	if(k%n!=0&&(k/n)%2==1)printf("%d %d",k/n+1,n-(k%n-1));
	return 0;
}
