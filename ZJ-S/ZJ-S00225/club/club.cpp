#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

struct V{
	int p[4],id[4];
	void init(){
		p[1]=read(),p[2]=read(),p[3]=read();
		if(p[1]>=p[2]&&p[1]>=p[3]){
			id[1]=1;
			if(p[2]>=p[3]) id[2]=2,id[3]=3;else id[2]=3,id[3]=2;
		}
		else if(p[2]>=p[1]&&p[2]>=p[3]){
			id[1]=2;
			if(p[1]>=p[3]) id[2]=1,id[3]=3;else id[2]=3,id[3]=1;
		}
		else{
			id[1]=3;
			if(p[1]>=p[2]) id[2]=1,id[3]=2;else id[2]=2,id[3]=1;
		}
	}
}lst[maxn];

struct Node{
	int val,nxtval,nxtid;
	bool operator<(const Node b)const{return (val-nxtval)>(b.val-b.nxtval);}
};
priority_queue<Node> q[4];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
    	n=read();
    	for(int i=1;i<=n;i++) lst[i].init();
    	for(int i=1;i<=n;i++){
    		if(q[lst[i].id[1]].size()==n/2)
    			if(lst[i].p[lst[i].id[1]]-lst[i].p[lst[i].id[2]]>=q[lst[i].id[1]].top().val-q[lst[i].id[1]].top().nxtval){
    				q[q[lst[i].id[1]].top().nxtid].push({q[lst[i].id[1]].top().nxtval,0,0});
					q[lst[i].id[1]].pop();
    				q[lst[i].id[1]].push({lst[i].p[lst[i].id[1]],lst[i].p[lst[i].id[2]],lst[i].id[2]});
				}else
					q[lst[i].id[2]].push({lst[i].p[lst[i].id[2]],0,0});
				
			else
				q[lst[i].id[1]].push({lst[i].p[lst[i].id[1]],lst[i].p[lst[i].id[2]],lst[i].id[2]});
			
		}
		int res=0;
		while(!q[1].empty()) res+=q[1].top().val,q[1].pop();
		while(!q[2].empty()) res+=q[2].top().val,q[2].pop();
		while(!q[3].empty()) res+=q[3].top().val,q[3].pop();
		cout<<res<<endl;
	}
    return 0;
}