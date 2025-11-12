#include<bits/stdc++.h>
using namespace std;
/*struct node
{
	int m,x;
};
bool cmp(node a,node b)
{
	
	return a.m>b.m;
}*/
long long int i,j,n,a[4][2],b[1000006][4],t,maxn=0,ans=0,s,f1f=0,f2f=0,f3f=0,q,midn,minn,k=0,v1[1000006],v2[1000006],v3[1000006];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		maxn=0;
		ans=0;
		f1f=0;f2f=0;f3f=0;
		memset(a,0,sizeof(a));
		cin>>n;
		q=n/2;
		for(i=1;i<=n;i++)
		{
			//cin>>b[i][1].m>>b[i][2].m>>b[i][3].x;
			//b[i][1].x=1;b[i][2].x=2;b[i][3].x=3;
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			maxn=max(b[i][1],max(b[i][2],b[i][3]));
			ans+=maxn;
			/*k=q;
			while(q--)
			{
				
			}
			if(a[f1f][0]<=q&&maxn>a[f1f][1])
			{
				a[f1f][0]++;
				a[f1f][1]=maxn;
			}
			if(s==1)
			f1f++;
			if(s==2)
			f2f++;
			if(s==3)*/
		}
		cout<<ans<<endl;
		sort(v1+1,v1+1+n);
		sort(v1+2,v1+2+n);
		sort(v1+2,v1+2+n);
		for(i=1;i<=n;i++)
		{
			maxn=max(b[i][1],max(b[i][2],b[i][3]));
			if(maxn==b[i][1])
			{
				midn=max(b[i][2],b[i][3]);
				minn=min(b[i][2],b[i][3]);
				f1f=1;
				if(midn==b[i][2])
				{
					f2f=2;
					f3f=3;
				}
				if(midn==b[i][3])
				{
					f2f=3;
					f3f=2;
				}
			}
			if(maxn==b[i][2])
			{
				midn=max(b[i][1],b[i][3]);
				minn=min(b[i][1],b[i][3]);
				f1f=2;
				if(midn==b[i][1])
				{
					f2f=1;
					f3f=3;
				}
				if(midn==b[i][3])
				{
					f2f=3;
					f3f=1;
				}
				
			}
			if(maxn==b[i][3])
			{
				midn=max(b[i][2],b[i][1]);
				minn=min(b[i][2],b[i][1]);
				f1f=3;
				if(midn==b[i][2])
				{
					f2f=2;
					f3f=1;
				}
				if(midn==b[i][1])
				{
					f2f=1;
					f3f=2;
				}
				
			}
		}
		
		/*cin>>n;
		for(i=1;i<=n;i++)
		cin>>b[i][1]>>b[i][2]>>b[i][3];*/
		
		
		
	}
	return 0;
}
