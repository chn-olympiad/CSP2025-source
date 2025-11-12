#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],s[5010],sum,g;
struct node{
	long long s,len,ma;
};
queue<node>q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push({a[1],1,a[1]});
	for(int k=2;k<=n;k++){
		g=q.size();
		for(int i=1;i<=g;i++){
			node t=q.front();
			q.pop();
			q.push({t.s+a[k],t.len+1,max(t.ma,a[k])});
			q.push({t.s,t.len,t.ma});
		}
		q.push({a[k],1,a[k]});
	}
	while(!q.empty()){
		node t=q.front();
		if(t.len>=3&&t.s>t.ma*2)sum++;
		q.pop();
	}
	cout<<sum;
}

