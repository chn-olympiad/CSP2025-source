#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],f[N],ans,lst=0,op,xo[N],p;
bool tr;
int read(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		tr=0;
		for(int j=lst;j<=i;j++){
			if(xo[j]==k){
				f[i]=max(f[i],f[lst]+1);
				p=i;
				tr=1;
			}else{
				xo[j]=xo[j]^a[i];
				f[i]=max(f[i],f[i-1]);
			}
		}
		if(tr)lst=p;
	}
//	for(int i=1;i<=n;i++)ans=max(f[i],ans);
	printf("%d",f[n]);
	return 0;
}
