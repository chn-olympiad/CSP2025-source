#include<bits/stdc++.h>
using namespace std;
const int maxa=500005;
int n,k,a[maxa],ans;
bool flg0,flg1,vis[maxa];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();  
		if(a[i]!=1) flg1=1;
	}
	if(!flg1)  printf("%d\n",n/2),exit(0);
	for(int i=1;i<=n;i++) if(!(0<=a[i]&&a[i]<=1)){flg0=1;break;}
	if(!flg0){
		int lst=1;
		for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		if(k==0) ans=n-ans; 
		printf("%d\n",ans);exit(0);
	}
	for(int i=1;i<=n;i++) if(!vis[i])
	for(int j=i;j<=n;j++) if(!vis[j]){
		int ss=0;bool ff=0;
		for(int l=i;l<=j;l++) if(!vis[l]) ss^=a[l];else{ff=1;break;}
		if(ff) break;
		if(ss==k&&!ff){
			for(int as=i;as<=j;as++) vis[as]=1;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

