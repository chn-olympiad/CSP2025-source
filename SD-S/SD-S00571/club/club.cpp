#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,t;
int a[100005][5];
int num[5];
int ans,l;
int mid;
int bfs(int d,int ch,int an,int n1,int n2,int n3)
{
	if(n1>mid||n2>mid||n3>mid)return 0;
	if(d==n)ans=max(ans,an);
	else
	{
		for(int i=1;i<=3;i++)
		bfs(d+1,i,an+a[d+1][i],n1+(i==1),n2+(i==2),n3+(i==3));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		num[1]=0;num[2]=0;num[3]=0;
		ans=0;
		cin>>n;
		mid=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			int m=max(a[i][1],max(a[i][2],a[i][3]));
			l=0;
			for(int j=1;j<=3;j++)
			if(a[i][j]==m&&(l==0||num[j]<num[l]))l=j;
			num[l]++;
			if(num[l]>n/2){
				flag=l;
				break;
			}
			ans+=m;
		}
		if(flag==0)cout<<ans;
		else
		{
			ans=0;
			bfs(1,1,a[1][1],1,0,0);
			bfs(1,2,a[1][2],0,1,0);
			bfs(1,3,a[1][3],0,0,1);
			cout<<ans;
		}
		if(t)cout<<endl;
	}
	return 0;
}

