#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int k,n,a[maxn],cnt;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int x;
//	if(a[1]==k) x=a[2],cnt++;else x=a[1];
if(k==1){	
	for(int i=1;i<=n;i++){

 	if(a[i]==k){
		++cnt;
	}
}
}
if(k==0)
for(int i=1;i<=n;i++){
	if(a[i]==k) ++cnt;
	if(a[i]==1&&a[i+1]==1) i++,cnt++;
}
	printf("%d\n",cnt);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
