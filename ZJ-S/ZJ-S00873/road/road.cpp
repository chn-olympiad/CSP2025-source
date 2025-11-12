#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
struct qp{
	int q,p;
};
vector<qp> a[10110];
priority_queue<qp> q;
int n,m,k,book[10110],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd();k=rd();
	for(int i=1;i<=m;i++){
		int x=rd(),y=rd(),z=rd();
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		int q=rd();
		for(int j=1;j<=n;j++){
		int y=rd(),z=rd();
		a[n+i].push_back({j,z});
		a[j].push_back({n+i,z});
		}
	}
	for(int i=0;i<a[1].size();i++){
		q.push(a[1][i]);
	}
	book[1]=1;
	for(int i=2;i<=n+k;i++){
		qp u=q.top();
		while(book[u.p]==1){
			q.pop();
			u=q.top();
		}
		q.pop();
		ans+=u.p;
		book[u.q]=1;
		for(int i=0;i<=a[u.q].size();i++){
			if(book[a[u.q][i].q]==0){
				q.push(a[u.q][i]);
			}
		}
	}
	cout<<ans;
	return 0;
}