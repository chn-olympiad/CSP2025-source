#include<bits/stdc++.h>
using namespace std;
struct str{
	int x[5],xid[5],c;
}a[100005];
long long ans[5],wn[5],id;
long long ca[100005],ct,s;
long long t,n,tmp;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(ca,0,sizeof(ca));
		ct=0;
		for(int i=1;i<=3;i++) 
			ans[i]=wn[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i].x[j];
				a[i].xid[j]=j;
			}
			if(a[i].x[1]<a[i].x[2])
			{tmp=a[i].x[1];a[i].x[1]=a[i].x[2];a[i].x[2]=tmp;tmp=a[i].xid[1];a[i].xid[1]=a[i].xid[2];a[i].xid[2]=tmp;}
			if(a[i].x[1]<a[i].x[3])
			{tmp=a[i].x[1];a[i].x[1]=a[i].x[3];a[i].x[3]=tmp;tmp=a[i].xid[1];a[i].xid[1]=a[i].xid[3];a[i].xid[3]=tmp;}
			if(a[i].x[2]<a[i].x[3])
			{tmp=a[i].x[2];a[i].x[2]=a[i].x[3];a[i].x[3]=tmp;tmp=a[i].xid[2];a[i].xid[2]=a[i].xid[3];a[i].xid[3]=tmp;}
			id=a[i].xid[1];
			wn[id]++;
			ans[id]+=a[i].x[1];
			a[i].c=id;
		}
		s=ans[1]+ans[2]+ans[3];
		for(int i=1;i<=3;i++) 
		{
			if(wn[i]>n/2)
			{
				id=i;
				for(int j=1;j<=n;j++)
				{
					if(a[j].c==i)
					{
						ca[ct++]=a[j].x[1]-a[j].x[2];
					}
				}
				sort(ca,ca+ct);
				for(int j=0;j<wn[i]-n/2;j++)
					s-=ca[j];
				break;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
