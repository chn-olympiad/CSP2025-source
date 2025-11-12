//#include<bits/stdc++.h>
//using namespace std;
//inline int read()
//{
//	int x=0,f=0;
//	char c=getchar();
//	while(!isdigit(c))
//	{
//		f|=c=='-';
//		c=getchar();
//	}
//	while(isdigit(c))
//	{
//		x=(x<<3)+(x<<1)+(c^48);
//		c=getchar();
//	}
//	return f?(-x):x;
//}
//int n;
//int a[100010][5];
//int num[100010];
//int cnt[5];
//struct node
//{
//	int x,v;//x原值，v差值 
//	int id1,id2;//id1当前id，id2次位id 
//	bool operator <(const node &y) const
//	{
//		return v<y.v; 
//	}
//};
//priority_queue<node>q[2];
//int M(int id,int numb)
//{
//	int aa[5];
//	int aa[1]=a[id][1],aa[2]=a[id][2],aa[3]=a[id][3];
//	sort(aa+1,aa+4);
//	return aa[numb];
//}
//int idm(int id,int v)
//{
//	for(int i=1;i<=3;i++)
//		if(a[id][i]==v)return i;
//}
//int main(){
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	int T;
//	T=read();
//	while(T--)
//	{
//		cnt[1]=cnt[2]=cnt[3]=0;
//		n=read();
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=3;j++)
//			{
//				a[i][j]=read();
//			}
//		}
//		int ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			int max1=M(i,1);
//			int max2=M(i,2);
//			int max3=M(i,3);
//			int id1=idm(i,max1);
//			int id2=idm(i,max2);			
//			int id3=idm(i,max3);
//			if(cnt[id1]==n/2)
//			{
//				node tmp=q.top();
//				int x=tmp.x;
//				int v=tmp.v;
//				int tmpid=tmp.id1;
//				int tmpidd=tmp.id2;
//				if(v+max1>0)
//				{
//					q.pop();
//					ans+=v+max1;
//					q.top()
//				}
//			}
//		}
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=0;
	char c=getchar();
	while(!isdigit(c))
	{
		f|=c=='-';
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f?(-x):x;
}int n;
struct node
{
	int v[5];
	int semax,semaxid;
	int Max,maxid;
}a[100010];
int M(int id,int numb)
{
	int aa[5];
	aa[1]=a[id].v[1],aa[2]=a[id].v[2],aa[3]=a[id].v[3];
	sort(aa+1,aa+4);
	return aa[3+1-numb];
}
int idm(int id,int v)
{
	for(int i=1;i<=3;i++)
		if(a[id].v[i]==v)return i;
}


int cnt[5];
int cmpid;
bool cmp(node x,node y)
{
	if(x.Max!=y.Max)
		return x.Max>y.Max;
	return x.semax-x.Max>y.semax-y.Max;
}
priority_queue<int>q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--)
	{
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty())q[i].pop();
		}
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i].v[1]=read();
			a[i].v[2]=read();			
			a[i].v[3]=read();
			int mmax=M(i,1);
			int mid=idm(i,mmax);
			a[i].Max=mmax;
			a[i].maxid=mid;
			a[i].semax=M(i,2);
			a[i].semaxid=idm(i,a[i].semax);
			if(a[i].semaxid==a[i].maxid)
			{
				for(int k=1;k<=3;k++)
				{
					if(a[i].v[k]==a[i].Max&&i!=a[i].maxid)
					{
						a[i].semaxid=i;
					}
				}
			}
		}
		int Max=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
//			printf("a[%d]max=%d\n",i,a[i].Max);
//			for(int k=1;k<=3;k++)
//			cout<<q[k].size();	
//				cout<<"check1??"<<endl;
			if(
			cnt[a[i].maxid]<n/2)
			{	
//			cout<<"check1??"<<endl;
				Max+=a[i].Max;
//					cout<<"c1"<<endl;
				cnt[a[i].maxid]++;	
//				cout<<"c2"<<a[io]<<endl;
				q[a[i].maxid].push(a[i].semax-a[i].Max);
//					cout<<"c3"<<endl;
			}	
			else
			{
//			cout<<"check2??"<<endl;
//				if(q[a[i].maxid].empty())
//				{
//					cout<<"check??"<<endl;
//				}
				int tmp=q[a[i].maxid].top();
				if(tmp+a[i].Max>a[i].semax)
				{
					q[a[i].maxid].pop();
					Max+=tmp+a[i].Max;
					q[a[i].maxid].push(a[i].semax-a[i].Max);
				}
//				else if(tmp+a[i].Max==0&&tmp<=a[i].semax-a[i].Max)
//				{
//					q[a[i].maxid].pop();
//					Max+=tmp+a[i].Max;
//					q[a[i].maxid].push(a[i].semax-a[i].Max);	
//				}
				else
				{
					Max+=a[i].semax;
				}
			}
		}
		printf("%d\n",Max);
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
3 1 1
3 1 1
2 1 1
1 1 0
*/
//		for(int i=1;i<=3;i++)
//		{
//			int ans=0;
//			cmpid=i;
//			sort(a[i]+1,a[i]+n+1,cmp);
//			for(int j=1;j<=n/2;j++)
//			{
//				ans+=a[i][j];
//			}
//			for(int j=n/2+1;j<=n;j++)
//			{
//				int mmax=0;
//				for(int k=1;k<=3;k++)
//				{
//					if(k==i)
//					{
//						mmax=max(mmax,a[k][j]);
//					}
//				}
//				ans+=mmax;
//			}
//			Max=max(Max,ans);
//		}