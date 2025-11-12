#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int _;
int n;
int tp[N];
int cnt_2,cnt_3;
long long ans;
int MAX;

struct node {
	int a,b,c;
} e[N];

struct jgt {
	int sum;
	int cnt_a,cnt_b,cnt_c;
	int pos;
};

void bfs() {
	queue<jgt> q;
	q.push({e[1].a,1,0,0,1});
	q.push({e[1].b,0,1,0,1});
	q.push({e[1].c,0,0,1,1});
	while(!q.empty()) {
		jgt now=q.front();
		q.pop();
		if(now.pos==n) {
			ans=max(ans,now.sum);
			continue;
		}
		int pos=now.pos+1;
		if(now.cnt_a+1<=MAX)
			q.push({now.sum+e[pos].a,now.cnt_a+1,now.cnt_b,now.cnt_c,pos});
		if(now.cnt_b+1<=MAX)
			q.push({now.sum+e[pos].b,now.cnt_a,now.cnt_b+1,now.cnt_c,pos});
		if(now.cnt_c+1<=MAX)
			q.push({now.sum+e[pos].c,now.cnt_a,now.cnt_b,now.cnt_c+1,pos});
	}
}

bool cmp(int x,int y) {
	return x>y;
}

void solve() {
	ans=0;
	cin>>n;
	MAX=n/2;
	for(int i=1; i<=n; i++) {
		cin>>e[i].a>>e[i].b>>e[i].c;
		tp[i]=e[i].a;
		if(e[i].b==0)cnt_2++;
		if(e[i].c==0)cnt_3++;
	}
	if(n==2) {
		int ans1=max(e[1].a+e[2].b,e[1].a+e[2].c);
		int ans2=max(e[1].b+e[2].a,e[1].b+e[2].c);
		int ans3=max(e[1].c+e[2].a,e[1].c+e[2].b);
		cout<<max(max(ans1,ans2),ans3)<<endl;
		return;
	}
	if(cnt_2==n&&cnt_3==n) {
		sort(tp+1,tp+n+1,cmp);
		for(int i=1; i<=n/2; i++) {
			ans+=tp[i];
		}
		cout<<ans<<endl;
		return;
	}
	bfs();
	cout<<ans<<endl;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}
//神兽保佑，代码无 bug!!!
