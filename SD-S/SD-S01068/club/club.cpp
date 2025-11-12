#include<bits/stdc++.h> 
using namespace std;
int t;
struct nod{
	int a,b,c,num;
	int caab,caac,cabc;
	bool operator < (const nod&h) const{
		return h.caab<caab;
	}
}peo[200000];
bool cmp(nod a,nod b)
{
	return a.a <b.a;
}
bool cam(nod a,nod b)
{
	return a.b<b.b;
}
bool cmp2(nod a,nod b)
{
	return b.c<a.c;
}
int so[200000];
int s[200000][3];
long long sum;
int n;
int num[4]={0,0,0,0};
int a2,a3,a1;
void so_so(long long sum1,int n1)
{
//	cout<<sum<<endl;
//	cout<<n1<<endl;
	if(n1==n+1)
	{
		sum=max(sum,sum1);
		return ;
	}
	if(num[1]<n/2&&a1!=0)
	{
		num[1]++;
//		cout<<sum1<<" "<<peo[n1].a<<" "<<num[1]<<" "<<n/2<<endl; 
		so_so(sum1+peo[n1].a,n1+1);
		num[1]--;
	}
	if(num[2]<n/2&&a2!=0)
	{
		num[2]++;
//		cout<<sum1<<" "<<peo[n1].b<<" "<<num[2]<<" "<<n/2<<endl;
		so_so(sum1+peo[n1].b,n1+1);
		num[2]--;
	}
	if(num[3]<n/2&&a3!=0)
	{
		num[3]++;
//		cout<<sum1<<" "<<peo[n1].c<<" "<<num[3]<<" "<<n/2<<endl;
		so_so(sum1+peo[n1].c,n1+1); 
		num[3]--;
	}
	
	return ;
}
priority_queue<nod> q1,q2; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//		cout<<110;
	cin>>t;
	while(t--)
	{
//		long long sum=0;
		sum=0;
		memset(so,0,sizeof(so));
		cin>>n;
		a3=0,a2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&peo[i].a,&peo[i].b,&peo[i].c);
//			cout<<1100<<endl;
			peo[i].num=i;
//			peo[i].caab=abs(peo[i].a-peo[i].b);
//			peo[i].caac=abs(peo[i].a-peo[i].c);
//			peo[i].cabc=abs(peo[i].b-peo[i].c);
			if(peo[i].b!=0) a2=1;
			if(peo[i].c!=0) a3=1;
			if(peo[i].a!=0) a1=1;
		}
		if(a2==0&&a3==0)
		{
			sort(peo+1,peo+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				sum+=peo[i].a;
			}
//			cout<<sum<<endl;
			continue;
		}
		
		if(n<=30)
		{
			so_so(0,1);
			cout<<sum<<endl;
			continue;
		}
		
		sort(peo+1,peo+n+1,cmp);
		int sheng=n;
		while(sheng>0&&num[1]<n/2)
		{
			if(peo[sheng].a>=peo[sheng].b&&peo[sheng].a>=peo[sheng].c)
			{
				sum+=peo[sheng].a;
////				cout<<peo[sheng].num<<" "<<sum<<" "<<'a'<<endl;
				so[peo[sheng].num]=1;
				num[1]++;
			}
//			else cout<<'a'<<" "<<peo[sheng].a<<" "<<peo[sheng].b<<" "<<peo[sheng].c<<" "<<num[1]<<endl;
			sheng--;
		}
		sheng=n;
		sort(peo+1,peo+n+1,cam);
		while(sheng>0&&num[2]<n/2)
		{
			if(peo[sheng].b>=peo[sheng].a&&peo[sheng].b>=peo[sheng].c&&so[peo[sheng].num]==0)
			{
				sum+=peo[sheng].b;
////				cout<<peo[sheng].num<<" "<<sum<<" "<<'b'<<endl;
				so[peo[sheng].num]=1;
				num[2]++;
			}
////			else cout<<'b'<<" "<<peo[sheng].a<<" "<<peo[sheng].b<<" "<<peo[sheng].c<<" "<<num[2]<<endl;
			sheng--;
		}
		sheng=n;
		sort(peo+1,peo+n+1,cmp2);
		while(sheng>0&&num[3]<n/2)
		{
			if(peo[sheng].c>=peo[sheng].a&&peo[sheng].c>=peo[sheng].b&&so[peo[sheng].num]==0)
			{
				sum+=peo[sheng].c;
////				cout<<peo[sheng].num<<" "<<sum<<" "<<'c'<<endl;
				so[peo[sheng].num]=1;
				num[3]++;
			}
////			else cout<<'c'<<" "<<peo[sheng].a<<" "<<peo[sheng].b<<" "<<peo[sheng].c<<" "<<num[3]<<endl;
			sheng--;
		}
		if(num[2]==n/2)
		{
			sheng=n;
			sort(peo+1,peo+n+1,cmp2);
			while(sheng>0&&num[3]<n/2)
			{
				if(peo[sheng].c>=peo[sheng].a&&so[peo[sheng].num]==0)
				{
					sum+=peo[sheng].c;
					so[peo[sheng].num]=1;
					num[3]++;
				}
			sheng--;
			}
			if(num[3]+num[2]+num[1]!=n)
			{
				for(int j=1;j<=n;j++)
				{
					if(so[peo[sheng].num]==0) sum+=peo[sheng].a;
				}
			}
		}
		if(num[3]==n/2)
		{
			sheng=n;
			sort(peo+1,peo+n+1,cam);
			while(sheng--&&num[3]<n/2)
			{
				if(peo[sheng].b>=peo[sheng].a&&so[peo[sheng].num]==0)
				{
					sum+=peo[sheng].b;
					so[peo[sheng].num]=1;
					num[2]++;
				}
			}
			if(num[3]+num[2]+num[1]!=n)
			{
				for(int j=1;j<=n;j++)
				{
					if(so[peo[sheng].num]==0) sum+=peo[sheng].a;
				}
			}
		
	}}



//	while(t--)
//	{
//		long long int sum=0;
//		memset(so,0,sizeof(so));
//		int num[4]={0,0,0,0};
//		int n;cin>>n;
//		int a2=0,a3=0;
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%d%d%d",&peo[i].a,&peo[i].b,&peo[i].c);
//			peo[i].num=i;
//			if(peo[i].b!=0) a2=1;
//			if(peo[i].c!=0) a3=1;
//		}
////		cout<<a2<<" "<<a3<<endl;
//		if(a2==0&&a3==0)
//		{
//			sort(peo+1,peo+n+1,cmp);
//			for(int i=1;i<=n/2;i++)
//			{
//				sum+=peo[i].a;
//			}
//			cout<<sum<<endl;
//			continue;
//		}
////		cout<<110<<endl; 
//		}
//		cout<<sum<<endl;
//	}
	return 0;
}
