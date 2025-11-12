#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N=100005;
const long long PIN=1e18;
int n,b[N],cnt[N],len; long long a[N][3],c[N];
int read(){
	char ch; int x=0;
	do ch=getchar();
	while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9')
		x=x*10+(ch-'0'),ch=getchar();
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,t,s1; long long ans,s2;
	for(t=read();t>0;t--){
		n=read(),ans=0,len=0;
		for(i=0;i< 3;i++) cnt[i]=0;
		for(i=1;i<=n;i++) b[i]=0;
		for(i=1;i<=n;i++){
			for(j=0;j< 3;j++) a[i][j]=read();
			for(j=1;j< 3;j++) if(a[i][j]>a[i][b[i]]) b[i]=j;
			ans+=a[i][b[i]],cnt[b[i]]++;
		}
		for(s1=0;s1<3;s1++) if(cnt[s1]>n/2) break;
		if(s1<3){
			for(i=1;i<=n;i++){
				if(b[i]!=s1) continue;
				for(s2=PIN,j=0;j<3;j++)
					if(j!=s1) s2=min(s2,a[i][s1]-a[i][j]);
				c[++len]=s2;
			}
			sort(c+1,c+len+1);
			for(i=1;i<=cnt[s1]-n/2;i++) ans-=c[i];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}