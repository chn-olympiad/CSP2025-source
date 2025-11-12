#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=0,k=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') k=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) f=f*10+ch-'0';
	return f*k;
}
int t,n;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		int a[3],b[100001]={0},c[3]={0},d[20001][3]={0},ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[0]=read();
			a[1]=read();
			a[2]=read();
			if(a[0]>=a[1]&&a[0]>=a[2]){
				ans+=a[0];
				c[0]++;
				b[i]=0;
				d[min(a[0]-a[1],a[0]-a[2])][0]++;
			}
			else if(a[1]>=a[0]&&a[1]>=a[2]){
				ans+=a[1];
				c[1]++;
				b[i]=1;
				d[min(a[1]-a[0],a[1]-a[2])][1]++;
			}
			else{
				ans+=a[2];
				c[2]++;
				b[i]=2;
				d[min(a[2]-a[1],a[2]-a[0])][2]++;
			}
		}
		for(int i=0;c[0]>n/2;i++){
			if(c[0]-d[i][0]<=n/2){
				d[i][0]=c[0]-(n/2);
			}
			c[0]-=d[i][0];
			ans-=i*d[i][0];
		}
		for(int i=0;c[1]>n/2;i++){
			if(c[1]-d[i][1]<=n/2){
				d[i][1]=c[1]-(n/2);
			}
			c[1]-=d[i][1];
			ans-=i*d[i][1];
		}
		for(int i=0;c[2]>n/2;i++){
			if(c[2]-d[i][2]<=n/2){
				d[i][2]=c[2]-(n/2);
			}
			c[2]-=d[i][2];
			ans-=i*d[i][2];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
