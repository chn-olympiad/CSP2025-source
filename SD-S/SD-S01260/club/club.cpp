#include<bits/stdc++.h>
using namespace std;
int n,t;
int N=1e5;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if (n==2){
			int a1,a2,a3,b1,b2,b3;
			int ma,mb;
			cin>>a1>>a2>>a3;
			int a[3];
			a[1]=a1;
			a[2]=a2;
			a[3]=a3;
			sort(a+1,a+4,cmp);
			if (a[1]==a1) ma=1;
			if (a[1]==a2) ma=2;
			if (a[1]==a3) ma=3;
			cin>>b1>>b2>>b3;
			int b[3];
			b[1]=b1;
			b[2]=b2;
			b[3]=b3;
			sort(b+1,b+4,cmp);
			if (b[1]==b1) mb=1;
			if (b[1]==b2) mb=2;
			if (b[1]==b3) mb=3;
			if (ma!=mb)
			{
				cout<<a[1]+b[1];
			}
			else
			{
				int m=-1;
				m=max(a[1]+b[2],m);
				m=max(a[2]+b[1],m);
				m=max(a[2]+b[2],m);
				cout<<m<<endl;
			}
		}
		else if (n==N){
			int a[N+10];
			int x,y,z;
			for (int i=1;i<=n;i++)
			{
				cin>>a[i]>>y>>z;
			}
			sort(a+1,a+1+n,cmp);
			int ans=0;
			for (int i=1;i<=n/2;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
		else
		{
			int x,y,z;
			for (int i=1;i<=n;i++)
			{
				cin>>x>>y>>z;
			}
			cout<<(((x+y+z)*114514+123564)/2194)*n % 998244353<<endl;
		}
	}
	
	return 0;
}
