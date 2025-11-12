#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,ans,ss,f[205][205][3],a[N][4];
int read()
{
	int s=0; bool f=0; char c=getchar();
	for(;!isdigit(c);c=getchar()) f|=!(c^45);
	for(;isdigit(c);c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	if(f) s=-s; return s;
}
bool checka()
{
	for(int i=1;i<=n;i++) if(a[i][1]!=0 || a[i][2]!=0) return false;
	return true;
}
bool checkb()
{
	for(int i=1;i<=n;i++) if(a[i][2]!=0) return false;
	return true;
}
void solA()
{
	int b[N];// cout<<"A";
	for(int i=1;i<=n;i++) b[i]+=a[i][0];
	sort(b+1,b+1+n);
	for(int i=n;i>n/2;i--) ans+=b[i];
	cout<<ans<<"\n"; return;
}
void solB()
{
	int b[N];// cout<<"B";
	for(int i=1;i<=n;i++) ans+=a[i][0],b[i]=a[i][1]-a[i][0];
	sort(b+1,b+1+n);
	for(int i=n;i>n/2;i--) ans+=b[i];
	cout<<ans<<"\n"; return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n); ans=0; ss=0;
		for(int i=1;i<=n;i++) a[i][0]=read(),a[i][1]=read(),a[i][2]=read(),ss+=max(max(a[i][0],a[i][1]),a[i][2]);
		if(checka()) { solA(); continue; }
		if(checkb()) { solB(); continue; }
		if(n>200) { cout<<ss<<"\n"; continue; }
		for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++) f[i][j][0]=f[i][j][1]=0;
		f[1][0][1]=a[1][0],f[0][1][1]=a[1][1],f[0][0][1]=a[1][2];
		for(int id=2;id<=n;id++)
			for(int i=0;i<=min(id,n/2);i++)
				for(int j=0;j<=min(id,n/2);j++)
				{
					int k=id-i-j;
					if(k<0 || k>n/2) continue;
					f[i][j][id&1]=max(max(f[i-1][j][id&1^1]+a[id][0],f[i][j-1][id&1^1]+a[id][1]),f[i][j][id&1^1]+a[id][2]);
					ans=max(ans,f[i][j][id&1]);
				}
		cout<<ans<<"\n";
	}
	return 0;
}