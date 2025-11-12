#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int ans;

struct node {
	int sum;
	int maxx;
	int cnt;
	int pos;//当前枚举到的下标
};
queue<node> q;

void bfs() {
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		int sum=now.sum,maxx=now.maxx,cnt=now.cnt,pos=now.pos;
		if(cnt>n||pos>n)continue;
//		printf("sum = %d, max = %d, cnt = %d, pos = %d\n",sum,maxx,cnt,pos);
		if(cnt>=3&&sum>maxx*2)ans++;
		int t=pos+1;
		q.push({sum+a[t],a[t],cnt+1,t});
		q.push({sum,maxx,cnt,t});
	}
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n-3; i++)q.push({a[i],a[i],1,i});
	bfs();
	cout<<ans-1<<endl;
	return 0;
}
//神兽保佑，代码无 bug !!!


