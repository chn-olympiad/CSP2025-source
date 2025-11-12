#include <bits/stdc++.h>
using namespace std;
int in(){
	int w = 0 , f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		w = (w<<3)+(w<<1)+(ch&15);
		ch = getchar();
	}
	return w*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = in();
	while(T--){
		priority_queue<int> q[4];
		int n = in();int ans = 0;
		for(int i = 1 ; i<=n ; i++){
			int a=in(),b=in(),c=in();
			ans+=max({a,b,c});
			if(a>=b&&a>=c) q[1].push(max(b,c)-a);
			else if(b>=a&&b>=c) q[2].push(max(a,c)-b);
			else  q[3].push(max(a,b)-c);
		}
		n>>=1;
		while(q[1].size()>n) ans+=q[1].top(),q[1].pop();
		while(q[2].size()>n) ans+=q[2].top(),q[2].pop();
		while(q[3].size()>n) ans+=q[3].top(),q[3].pop();
		printf("%d\n",ans);
	}
	return 0;
}