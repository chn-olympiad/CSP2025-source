#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int num[4];
long long s;
struct node{
	int a[4];
	int cha1;
	int cha2;
	int maxn;
	int secn;
	int minn;
	int maxnn;
	int secnn;
	int minnn;
	int whi;
}m[10005],mmm[10005];
bool cmp(node a,node b)
{
	if(!(a.cha1==b.cha1))
	{
		return a.cha1<b.cha1;
	}
	return a.cha2<b.cha2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int M=0;M<T;M++)
	{
		int w;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].a[1]>>m[i].a[2]>>m[i].a[3];
			m[i].maxn=max(m[i].a[3],max(m[i].a[1],m[i].a[2]));
			m[i].minn=min(m[i].a[3],min(m[i].a[1],m[i].a[2]));
			for(int j=1;j<=3;j++)
			{
				if(m[i].a[j]==m[i].maxn) m[i].maxnn=j;
				if(m[i].a[j]==m[i].minn) m[i].minnn=j;
			}
			m[i].secn=m[i].a[1]+m[i].a[2]+m[i].a[3]-m[i].maxn-m[i].minn;
			m[i].secnn=6-m[i].maxnn-m[i].minnn;
			m[i].cha1=m[i].maxn-m[i].secn;
			m[i].cha2=m[i].secn-m[i].minn;
			m[i].whi=m[i].maxnn;
			num[m[i].whi]++;
			s+=m[i].a[m[i].whi];
		}
		if(max(num[3],max(num[1],num[2]))>(n/2))
		{
			for(int i=1;i<=3;i++)
			{
				if(num[i]==max(num[3],max(num[1],num[2]))) w=i;
			}
			int k=1;
			for(int j=1;j<=n;j++)
			{
				if(m[j].whi==w)
				{
					mmm[k++]=m[j];
				}
			}
			sort(mmm+1,mmm+k,cmp);
			int j=1;
			while(num[w]>(n/2))
			{
				num[w]--;
				s=s-mmm[j].cha1;
				j++;
			}
		}
		cout<<s<<endl;
		s=0;
		for(int i=0;i<=n;i++)
		{
			m[i].a[1]=0;
			m[i].a[2]=0;
			m[i].a[3]=0;
			m[i].maxn=0;
			m[i].minn=0;
			m[i].secn=0;
			m[i].maxnn=0;
			m[i].minnn=0;
			m[i].secnn=0;
			m[i].cha1=0;
			m[i].cha2=0;
			m[i].whi=0;
			mmm[i].a[1]=0;
			mmm[i].a[2]=0;
			mmm[i].a[3]=0;
			mmm[i].maxn=0;
			mmm[i].minn=0;
			mmm[i].secn=0;
			mmm[i].maxnn=0;
			mmm[i].minnn=0;
			mmm[i].secnn=0;
			mmm[i].cha1=0;
			mmm[i].cha2=0;
			mmm[i].whi=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
