#include<bits/stdc++.h>
using namespace std;
int t,n,k;
long long cnt;
struct ma{
	int a,b,c;
}a[200010];
void f(int x,int y,int z,int j,long long sum)
{
	if(j>n)
	{
		cnt=max(cnt,sum);
		return ;
	}
	if(x<k)
	f(x+1,y,z,j+1,sum+a[j].a);
	if(y<k)
	f(x,y+1,z,j+1,sum+a[j].b);
	if(z<k)
	f(x,y,z+1,j+1,sum+a[j].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		k=n/2;
		cnt=0;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		f(0,0,0,0,0);
		cout<<cnt<<endl;
	}
	return 0;
}
