#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e5+5;
struct node{
	int u,v,w;
	bool operator<(node b)const{
		return w<b.w;
	}
};
int n;
int a[N][3];
int p[N];
priority_queue<node> q[3];
void add(int i,int x){
	if(x!=0)q[x].push({i,0,a[i][0]-a[i][x]});
	if(x!=1)q[x].push({i,1,a[i][1]-a[i][x]});
	if(x!=2)q[x].push({i,2,a[i][2]-a[i][x]});
	p[i]=x;
}
void print(priority_queue<node> q){
	while(!q.empty()){
		node nw=q.top();q.pop();
		cout<<nw.u<<" "<<nw.v<<" "<<nw.w<<"\n";
	}
}
void work(){
	int as=0;
	int sz[3]={0,0,0};
	n=read();
	for(int i=0;i<3;i++)
		while(!q[i].empty())
			q[i].pop();
	for(int i=1;i<=n;i++){
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		int rs[3]={0,0,0};
		rs[0]=a[i][0];
		rs[1]=a[i][1];
		rs[2]=a[i][2];
		while(!q[0].empty()&&p[q[0].top().u]!=0)
			q[0].pop();
		while(!q[1].empty()&&p[q[1].top().u]!=1)
			q[1].pop();
		while(!q[2].empty()&&p[q[2].top().u]!=2)
			q[2].pop();
		if(sz[0]==n/2)rs[0]+=q[0].top().w;
		if(sz[1]==n/2)rs[1]+=q[1].top().w;
		if(sz[2]==n/2)rs[2]+=q[2].top().w;
		for(int j=0;j<3;j++){
			if(rs[j]>=rs[0]&&rs[j]>=rs[1]&&rs[j]>=rs[2]){
				as+=rs[j];
//				cout<<i<<" "<<j<<" "<<rs[j]<<"!\n";
				if(sz[j]+1>n/2){
					while(p[q[j].top().u]!=j)
						q[j].pop();
					node nw=q[j].top();q[j].pop();
//					cout<<nw.u<<" "<<nw.v<<" "<<nw.w<<"?\n";
					add(nw.u,nw.v),sz[j]--;
				}
				add(i,j),sz[j]++;
				break;
			}
		}
//		for(int k=0;k<3;k++){
//			cout<<k<<"------------\n";
//			print(q[k]);
//			cout<<k<<"------------\n";
//		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<p[i]<<" \n"[i==n];
	cout<<as<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--)work();
	return 0;
}

