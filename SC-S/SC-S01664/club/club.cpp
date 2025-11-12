#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
struct node{
	int t,d,u;
	friend bool operator < (node u,node v){
		return u.d>v.d;
	}
};
int mid(int f,int g,int h){
	int mx=max({f,g,h});
	int mn=min({f,g,h});
	int q=0,z=0;
	if(f==mx)q++;
	if(g==mx)q++;
	if(h==mx)q++;
	if(f==mn)z++;
	if(g==mn)z++;
	if(h==mn)z++;
	if(q>1)return mx;
	if(z>1)return mn;
	if(f!=mx&&f!=mn)return f;
	if(g!=mx&&g!=mn)return g;
	if(h!=mx&&h!=mn)return h;
}
int midp(int f,int g,int h,int num){
	int md=mid(f,g,h);
	if(f==md&&num!=1)return 1;
	if(g==md&&num!=2)return 2;
	return 3;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		priority_queue<node>q[5];
		for(int i=1;i<=n;i++){
			int mx=max({a[i][1],a[i][2],a[i][3]});
			if(a[i][1]==mx)q[1].push(node{i,mx-mid(a[i][1],a[i][2],a[i][3]),midp(a[i][1],a[i][2],a[i][3],1)});
			else if(a[i][2]==mx)q[2].push(node{i,mx-mid(a[i][1],a[i][2],a[i][3]),midp(a[i][1],a[i][2],a[i][3],2)});
			else q[3].push(node{i,mx-mid(a[i][1],a[i][2],a[i][3]),midp(a[i][1],a[i][2],a[i][3],3)});
		}
		while((int)q[1].size()>n/2||(int)q[2].size()>n/2||(int)q[3].size()>n/2){
			if((int)q[1].size()>n/2){
				q[q[1].top().u].push(q[1].top());
				q[1].pop();
			}
			if((int)q[2].size()>n/2){
				q[q[2].top().u].push(q[2].top());
				q[2].pop();
			}
			if((int)q[3].size()>n/2){
				q[q[3].top().u].push(q[3].top());
				q[3].pop();
			}
		}
		int sum=0;
		for(int i=1;i<=3;i++)while(!q[i].empty())sum+=a[q[i].top().t][i],q[i].pop();
		cout<<sum<<"\n";
	}
	return 0;
}