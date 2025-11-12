#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long a=0;
	short b=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') b=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<3)+(a<<1)+c-48;
		c=getchar();
	}
	return a*b;
}
struct ak{
	int V,W,next;
};
ak ac[1000005];
int ans[10005];
int que[1000005];
int head[10005],cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=2;i<=10005;i++) ans[i]=-1;
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		cnt++;
		ac[cnt].next=head[u];
		ac[cnt].V=v;
		ac[cnt].W=w;
		head[u]=cnt;
		cnt++;
		ac[cnt].next=head[v];
		ac[cnt].V=u;
		ac[cnt].W=w;
		head[v]=cnt;
	}
	int t=0,w=0;
	que[0]=1;
	while(t<=w){
		int T=ac[que[t]].next;
		while(T!=0){
			if(ans[que[T]]==-1){
				ans[que[T]]=ans[que[t]]+ac[que[T]].W;
				que[++w]=que[T];
			}
			else ans[que[T]]=min(ans[que[T]],ans[que[t]]+ac[que[T]].W);
			T=ac[T].next;
		}
		t++;
	}
	int ANS=0;
	for(int i=1;i<=n;i++){
		ANS=max(ANS,ans[i]);
	}
	cout <<ANS;
	fclose(stdin);
	fclose(stdout);
	return 0;
}