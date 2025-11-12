#include<bits/stdc++.h>
using namespace std;
int n,z[4],mid,c[4],mid,dis[4],ma,ans;

struct node{
	int a,b,c,ac,bc,cb,ca,ba,ab,x;
}a[100001];

struct fff{
	int z,q;
}d[200002];

bool aaa(int xx,int yy){
	return xx>yy;
}


int main() 
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		ma=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].x=i;
			a[i].ab=a[i].b-a[i].a;
			a[i].ba=0-a[i].ab;
			a[i].ac=a[i].c-a[i].a;
			a[i].ca=0-a[i].cb;
			a[i].bc=a[i].c-a[i].b;
			a[i].cb=0-a[i].bc;
			c[1]+=a[i].a;
			c[2]+=a[i].b;
			c[3]+=a[i].c;
		}
		
		mid=0;
		if(c[3]>=c[2]&&c[3]>=c[1])
		{
			ans=c[3];
			for(int i=1;i<=n;i++)
			{
				mid++;
				d[mid].z=a[i].cb;
				d[mid].q=2;
				mid++;
				d[mid].z=a[i].ca;
				d[mid].q=1
			}
			sort(d+1,d+mid,emp);
			for(int i=1;i<=ma;i++)
			{
				ans+=d[i].z;
				dis[d[i].q]++;
			}
			
		}
		
	}
	
	
}






