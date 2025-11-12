#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int num=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
const int N=1e5+5;
int a[N][5];
int b[5];
int ansmax[5];
void dfs(int x,int type,int ans,int n){
	if(x==n+1){
		 ansmax[type]=max(ans,ansmax[type]);
		 return ;
	}
	for(int i=1;i<=3;i++){
		if(b[i]<n/2){
			b[i]++;
			dfs(x+1,i,ans+a[x][i],n);
			b[i]--;
		}
	}
	return ;
}
void dfs2(int x,int type,int ans,int n){
	if(x==n+1){
		 ansmax[type]=max(ans,ansmax[type]);
		 return ;
	}
	for(int i=1;i<=3;i++){
		if(b[i]<n/2){
			b[i]++;
			dfs(x+1,i,ans+a[x][i],n);
			b[i]--;
		}
	}
	return ;
}
int p[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		memset(ansmax,0,sizeof(ansmax));
		int n=read();
		int A2=0,A3=0;
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			A2+=a[i][2];
			a[i][3]=read();
			A3+=a[i][3];
		}
		if(A2+A3==0){
			for(int i=1;i<=n;i++){
				p[i]=a[i][1];
			}
			sort(p+1,p+1+n);
			int ans=0;
			for(int i=n;i>n/2;i--){
				ans+=p[i];
			}
			printf("%lld\n",ans);
		}else if(A3!=0){
			if(n<20){
				dfs(1,0,0,n);
				printf("%lld\n",max(ansmax[1],max(ansmax[2],ansmax[3])));
			}else{
				int cnt=0;
				for(int i=1;i<=n;i++){
					cnt+=max(max(a[i][1],a[i][3]),a[i][2]);
				}
				printf("%lld\n",cnt);
			}
			
			
		}else{
			if(n<20){
				dfs2(1,0,0,n);
				printf("%lld\n",max(ansmax[1],max(ansmax[2],ansmax[3])));
			}else{
				int cnt=0;
				for(int i=1;i<=n;i++){
					cnt+=max(max(a[i][1],a[i][3]),a[i][2]);
				}
				printf("%lld\n",cnt);
			}
		}
	} 
	return 0;
 }

