#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,a[maxn],f[maxn],ans;
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
	for(int i=1;i<=n;i++)a[i]=read();
	int x=0;
	for(int i=1;i<=n;i++){
		x^=a[i];
		if(x==k){ans++;x=0;continue;}
		if(a[i]==k)ans++,x=0;
	}
	printf("%d\n",ans);
	return 0;
}