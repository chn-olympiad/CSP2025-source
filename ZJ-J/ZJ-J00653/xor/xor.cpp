#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500025];
int f[500025];
struct node{
	int start,end;
};
bool operator<(node a,node b){
	return a.end>b.end;
}
priority_queue<node>q;
queue<int> t[(1<<21)+25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		t[f[i]].push(i);
	}for(int i=1;i<=n;i++){
		if(!t[f[i-1]^k].empty()){
			q.push(node{i,t[f[i-1]^k].front()});
		}t[f[i]].pop();
	}q.push(node{n+1,n+1});
	int t=0;
	int ans=0;
	for(;;){
		if(t>n) break;
		while(q.top().start<=t) q.pop();
		node p=q.top();
		if(p.end>n) break;
		ans++,t=p.end;
		q.pop();
	}cout<<ans;
	return 0;
}
