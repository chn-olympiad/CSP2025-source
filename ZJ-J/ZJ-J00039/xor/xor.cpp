#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char ch=getchar();int f=1,ret=0;
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+(ch&15),ch=getchar();
	return f*ret;
}
int n,k,a[500005],m,ans;
int f[500005];
struct HXYT{
	int l,r;
	bool operator <(const HXYT& other)const{return l<other.l;}
}b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(x==k){b[++m]=(HXYT){i,i};continue;}
		for(int j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k){b[++m]=(HXYT){i,j};break;}
		}
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)f[i]=1;
	for(int i=1;i<=m;i++)for(int j=1;j<=i;j++)if(b[j].r<b[i].l)f[i]=max(f[i],f[j]+1);
	for(int i=1;i<=m;i++)ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}
