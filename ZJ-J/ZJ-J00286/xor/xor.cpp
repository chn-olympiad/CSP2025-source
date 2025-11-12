#include<bits/stdc++.h>
using namespace std;
int ans,n,a[500005],d,k,f[500005][5],ff[500005],m;
inline int read(){
	int ret(0),f(1);char ch(getchar());
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int yh(int x,int y){
	int a[25],l,r,ret=0;
	memset(a,0,sizeof(a));
	for(int i=1;x>0||y>0;++i){
		l=x%2,r=y%2,x/=2,y/=2,a[0]++;
		if(l==r) a[i]=0;
		else a[i]=1;
	}
	l=1;
	for(int i=1;i<=a[0];++i) ret+=l*a[i],l*=2;
	return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) if(a[i]!=1){d=1;break;}
	if(d==0){
		if(k>=2) printf("0\n");
		else if(k==0) printf("%d\n",n/2);
		else if(k==1) printf("%d\n",n);
		return 0;
	}
	for(int i=1;i<=n;++i) if(a[i]>1){d=0;break;}
	if(d==1){
		if(k>=2){printf("0\n");return 0;}
		if(k==0){
			for(int i=1;i<=n;++i)
				if(a[i]==0) ++ans;
				else if(a[i]==a[i]+1&&a[i]==1) ++i,++ans;
			printf("%d\n",ans);
		}else{
			for(int i=1;i<=n;++i) if(a[i]==1) ++ans;
			printf("%d\n",ans);
		}
		return 0;
	}
	for(int i=2;i<=n;++i) a[i]=yh(a[i],a[i-1]);
	for(int i=1;i<=n;++i) for(int j=i;j>=1;--j) if(yh(a[i],a[j-1])==k){f[++m][1]=j,f[m][2]=i;break;}
	for(int i=1;i<=m;++i){
		ff[i]=1;
		for(int j=1;j<i;++j) if(f[j][2]<f[i][1]) ff[i]=max(ff[i],ff[j]+1);
	}
	for(int i=1;i<=n;++i) ans=max(ans,ff[i]);
	printf("%d\n",ans);
	return 0;
}