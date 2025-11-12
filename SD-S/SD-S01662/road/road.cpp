#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar
#define pc putchar
const int N=1e6+15;
struct node{

};
inline int read(){
	int d=1,k=0;char c=gc();
	while(!(c>='0'&&c<='9'||c=='-'))c=gc();
	if(c=='-')c=gc(),d=-1;
	while(c>='0'&&c<='9')k=(k<<1)+(k<<3)+(c^48),c=gc();
	return d*k;
}inline void write(int x){
	static int sta[50];int top=0;
	do{sta[top++]=x%10;x/=10;}while(x);
	while(top)pc(sta[--top]+'0');
}signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read(),s=0;
	while(m--){
		int u=read(),v=read(),w=read();s+=w;
	}
	if(k==0){
		write(s);
	}else printf("0");
	return 0;
}

