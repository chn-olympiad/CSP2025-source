//SN-J00770 wangzihan JIAODAFUZHANGCHANBAYOUANXUEXIAO
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m,b[101],x,k,h,ha,li;
	cin>>n>>m;
	b[1]=x;
	cin>>x;
	for(int y=2;y<=m*n;y++)
	{
		cin>>b[y];
	}
	for(int i=1;i<=n*m-1;i++)
	for(int j=2;j<=n*m;j++){
		if(b[i]<b[j])
		{
			k=b[i]+b[j];
			b[i]=k-b[i];
			b[j]=k-b[j];
		}
	}
	for(int i=1;i<=n*m;i++){
		if (b[i]=x)
		h=i;
	}
	li=h/(2*n)*2;
	ha=h%(2*n);
	if(ha=0)
	cout<<li<<" "<<1;
	if(ha>n)
	cout<<li+1<<" "<<2*n-ha+1;
	if(ha<=n)
	cout<<li+1<<" "<<ha+1;
	return 0;
}
