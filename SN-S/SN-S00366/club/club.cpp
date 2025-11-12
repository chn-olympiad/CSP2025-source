#include <iostream>
#include <cstdio>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int atob[100005];
int atoc[100005];
int btoa[100005];
int btoc[100005];
int ctoa[100005];
int ctob[100005];
int maxx(int a,int b){
	if(a>b) return a;
	else return b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			atob[j]=b[j]-a[j];
			atoc[j]=c[j]-a[j];
			btoa[j]=(-atob[j]);
			btoc[j]=c[j]-b[j];
			ctoa[j]=(-atoc[j]);
			ctob[j]=(-btoc[j]);
		}
		int aa=0,bb=0,cc=0;
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			int v=maxx(a[i],maxx(b[i],c[i]));
			if(v==a[i]) aa+=1;
			else if(v==b[i]) bb+=1;
			else cc+=1;
			cnt+=v;
			if(aa>(n/2))
			{
				long long maxn=-1000000000000000;
				int p=0;
				char pl='a';
				for(int k=0;k<=j;k++)
				{
					if(atob[k]>maxn)
					{
						maxn=atob[k];
						p=k;
						pl='b';
					}
					if(atoc[k]>maxn)
					{
						maxn=atoc[k];
						p=k;
						pl='c';
					}
				}
				aa-=1;
				if(pl=='b')
				{
					bb+=1;
					cnt+=b[p];
				}
				if(pl=='c')
				{
					cc+=1;
					cnt+=c[p];
				}
				cnt-=v;
			}
			if(bb>(n/2))
			{
				long long maxn=-1000000000000000;
				int p=0;
				char pl='b';
				for(int k=0;k<=j;k++)
				{
					if(btoa[k]>maxn)
					{
						maxn=btoa[k];
						p=k;
						pl='a';
					}
					if(btoc[k]>maxn)
					{
						maxn=btoc[k];
						p=k;
						pl='c';
					}
				}
				bb-=1;
				cnt-=v;
				if(pl=='a')
				{
					aa+=1;
					cnt+=a[p];
				}
				if(pl=='c')
				{
					cc+=1;
					cnt+=c[p];
				}
			}
			if(cc>(n/2))
			{
				long long maxn=-1000000000000000;
				int p=0;
				char pl='b';
				for(int k=0;k<=j;k++)
				{
					if(ctoa[k]>maxn)
					{
						maxn=ctoa[k];
						p=k;
						pl='a';
					}
					if(ctob[k]>maxn)
					{
						maxn=ctob[k];
						p=k;
						pl='b';
					}
				}
				cc-=1;
				cnt-=v;
				if(pl=='b')
				{
					bb+=1;
					cnt+=b[p];
				}
				if(pl=='a')
				{
					aa+=1;
					cnt+=a[p];
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
