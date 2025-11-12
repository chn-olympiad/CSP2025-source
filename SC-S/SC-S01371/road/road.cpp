#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct r{
    long long from,to,need;
}road[2000001];
struct d{
	long long build;
	long long cost[2000001];
}new_city[11];
long long father[2000001];
long long half;
long long is_conect;
long long up;
long long now;
long long fans,tans;
long long ans;
bool fs,ts;
bool amp(r a,r b) {
	if (a.need!=b.need) return a.need<b.need;
	else if (a.need==b.need) return a.from<b.from;
	return a.to<=b.to;
}
long long ansestor(long long son) {
	if (father[son]==son) return son;
	return ansestor(father[son]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) father[i]=i;
	for (int i=1;i<=m;i++) cin>>road[i].from>>road[i].to>>road[i].need;
	for (int i=1;i<=k;i++) {
		cin>>new_city[i].build;
		for (int j=1;j<=n;j++) cin>>new_city[i].cost[j];
	}
	up=m;
	for (int i=1;i<=k;i++) {
		for (int j=1;j<n;j++) {
			for (int k=(j+1);k<=n;k++) {
				up++;
				road[up].from=j;
				road[up].to=k;
				road[up].need=(new_city[i].cost[j]+new_city[i].cost[k]+new_city[i].build);
			}
		}
	}
	sort(road+1,road+up+1,amp);
	while (is_conect!=n) {
		now++;
		fans=ansestor(road[now].from);
		tans=ansestor(road[now].to);
		if (fans!=tans) {
			ans+=road[now].need;
			fs=false,ts=false;
			if (father[road[now].from]==road[now].from) {
				fs=true;
				is_conect++;
			}
			if (father[road[now].to]==road[now].to) {
				ts=true;
				is_conect++;
			}
			if ((fs&&ts)||(fs&&(!ts))) father[road[now].from]=road[now].to;
			else if (!fs&&ts) father[road[now].to]=road[now].from;
			else father[fans]=tans;
		}
	}
	cout<<ans;
	return 0;
}
