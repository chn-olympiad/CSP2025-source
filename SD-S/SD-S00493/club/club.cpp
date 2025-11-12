#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int t,n,a,b,c,sum;
int ida[N],idb[N],idc[N],cnta,cntb,cntc;
struct T{
	int num,id;
}d[N];
bool cmp(T p,T q)
{
	return p.num<q.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cnta=cntb=cntc=sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			int x=a,y=b,z=c;
			if(x>=y&&x>=z)
			{
				a=x;
				if(y>=z) b=y,c=z;
				else b=z,c=y;
			}
			if(y>=x&&y>=z)
			{
				a=y;
				if(x>=z) b=x,c=z;
				else b=z,c=x;
			}
			if(z>=x&&z>=y)
			{
				a=z;
				if(x>=y) b=x,c=y;
				else b=y,c=x;
			}
			d[i].num=a-b;
			sum+=a;
			if(a==x)
			{
				d[i].id=1;
				cnta++;
			}
			if(a==y&&d[i].num!=0)
			{
				d[i].id=2;
				cntb++;
			}
			if(a==z)
			{
				d[i].id=3;
				cntc++;
			}
		}
//		cout<<endl<<sum<<endl;
//		cout<<cnta<<" "<<cntb<<" "<<cntc<<endl;
		sort(d+1,d+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<d[i].num<<" "<<d[i].id<<endl;
//		cout<<endl;
		if(cnta>n/2)
		{
			int k=cnta-n/2;
//			cout<<k<<endl;
			for(int i=1;i<=n;i++)
			{
				if(d[i].id==1) sum-=d[i].num,k--;
				if(k==0) break;
			}
		}
		if(cntb>n/2)
		{
			int k=cntb-n/2;
			for(int i=1;i<=n;i++)
			{
				if(d[i].id==2) sum-=d[i].num,k--;
				if(k==0) break;
			}
		}
		if(cntc>n/2)
		{
			int k=cntc-n/2;
			for(int i=1;i<=n;i++)
			{
				if(d[i].id==3) sum-=d[i].num,k--;
				if(k==0) break;
			}
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//password:Ren5Jie4Di4Ling5%

