#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,fg=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fg=1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return fg?(~(x-1)):x;
}
int T,n,ans;
priority_queue<int>q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    T=read();
    while(T--){
    	n=read(),ans=0;
    	for(int i=1;i<=n;i++){
    		int x=read(),y=read(),z=read();
    		int mx=max(x,y); mx=max(mx,z);
    		if(x==mx) q[0].push(max(y,z)-x);
    		else if(y==mx) q[1].push(max(x,z)-y);
    		else q[2].push(max(x,y)-z); ans+=mx;
		}
		for(int i=0;i<3;i++){
			while(q[i].size()>n/2)
				ans+=q[i].top(),q[i].pop();
			while(q[i].size()) q[i].pop();
		}
		printf("%d\n",ans);
	}
    return 0;
}




