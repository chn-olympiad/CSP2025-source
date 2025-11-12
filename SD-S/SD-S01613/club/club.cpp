#include<bits/stdc++.h>
using namespace std;
char *p1,*p2,buf[1000010]; 
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
int read(){
	int x=0;
	char c=gc();
	while(c<48)c=gc();
	while(47<c)x=(x<<3)+(x<<1)+(c&15),c=gc();
	return x;
}
int a[100010][3],b[3][100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read(),n,cnt[3],ans,mx;
	while(T--){
		n=read();
		cnt[0]=cnt[1]=cnt[2]=ans=0;
		for(int i=1;i<=n;++i){
			a[i][0]=read();
			a[i][1]=read();
			a[i][2]=read();
		}
		for(int i=1;i<=n;++i){
			mx=max(max(a[i][0],a[i][1]),a[i][2]);
			ans+=mx;
			if(mx==a[i][0])b[0][++cnt[0]]=max(a[i][1],a[i][2])-mx;
			else if(mx==a[i][1])b[1][++cnt[1]]=max(a[i][0],a[i][2])-mx;
			else b[2][++cnt[2]]=max(a[i][0],a[i][1])-mx;
		}
		for(int i=0;i<3;++i){
			if(cnt[i]>n>>1){
				nth_element(b[i]+1,b[i]+(n>>1),b[i]+cnt[i]+1);
				for(int j=(n>>1)+1;j<=cnt[i];++j)ans+=b[i][j];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
