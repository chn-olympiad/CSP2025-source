#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,f[maxn],ans,cnt;
struct Node{
	int L,R;
	bool operator <(const Node &B)const{return R<B.R;}
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		int x=read();
		f[i]=f[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[j]^f[i-1]==k)cnt++,a[cnt].L=i,a[cnt].R=j;
		}
	}
	int x=0;
	sort(a+1,a+1+cnt);
	for(int i=1;i<=cnt;i++){
		if(a[i].L>a[x].R)x=i,ans++;
	}
	printf("%d\n",ans);
	return 0;
}