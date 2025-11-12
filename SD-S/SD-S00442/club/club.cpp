#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int t;
int n;

int a[N][5];
int ans;
int bel[N];
int sum[5];
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii> > q_12;
priority_queue<pii,vector<pii>,greater<pii> > q_13;
priority_queue<pii,vector<pii>,greater<pii> > q_21;
priority_queue<pii,vector<pii>,greater<pii> > q_23;
priority_queue<pii,vector<pii>,greater<pii> > q_31;
priority_queue<pii,vector<pii>,greater<pii> > q_32;
//需要减去的数值
int lim;
#define cs cout<<"here";

void solve1(int i) {
	if(sum[1]<lim) {
		sum[1]++;
		bel[i] = 1;
		ans+=a[i][1];
		q_12.push({a[i][1]-a[i][2],i});
		q_13.push({a[i][1]-a[i][3],i});
		return;
	}
	ans+=a[i][1];
	
	//移动别的
	int to_2 = a[i][1]-a[i][2];
	int to_3 = a[i][1]-a[i][3];
	
	pii t2 = q_12.top();
	while(bel[t2.second]!=1) {
		q_12.pop();
		t2 = q_12.top();
	}
	pii t3 = q_13.top();
	while(bel[t3.second]!=1) {
		q_13.pop();
		t3 = q_13.top();
	}
	
	int minn = min(to_2,min(to_3,min(t2.first,t3.first)));
	ans-=minn;
	if(to_2 == minn) {
		bel[i] = 2;
		sum[2]++;
		q_21.push({a[i][2]-a[i][1],i});
		q_23.push({a[i][2]-a[i][3],i});
		return;
	}
	if(to_3 == minn) {
		bel[i] = 3;
		sum[3]++;
		q_31.push({a[i][3]-a[i][1],i});
		q_32.push({a[i][3]-a[i][2],i});
		return;
	}
	if(t2.first == minn) {
		bel[t2.second] = 2;  //t2.first去2
		sum[2]++;
		bel[i] = 1;
		q_12.pop();

		q_21.push({a[t2.second][2]-a[t2.second][1],t2.second});
		q_23.push({a[t2.second][2]-a[t2.second][3],t2.second});

		q_12.push({a[i][1]-a[i][2],i});
		q_13.push({a[i][1]-a[i][3],i});
		return;
	}
	if(t3.first == minn) {
		bel[t3.second] = 3;
		sum[3]++;
		bel[i] = 1;

		q_13.pop();

		q_31.push({a[t3.second][3]-a[t3.second][1],t3.second});
		q_32.push({a[t3.second][3]-a[t3.second][2],t3.second});

		q_12.push({a[i][1]-a[i][2],i});
		q_13.push({a[i][1]-a[i][3],i});
		return;
	}
}


void solve2(int i) {
	if(sum[2]<lim) {
		sum[2]++;
		bel[i] = 2;
		ans+=a[i][2];
		q_21.push({a[i][2]-a[i][1],i});
		q_23.push({a[i][2]-a[i][3],i});
		return;
	}
	ans+=a[i][2];
	int type = 0;
	//移动别的
	int to_1 = a[i][2]-a[i][1];
	int to_3 = a[i][2]-a[i][3];
	pii t1 = q_21.top();
	while(bel[t1.second]!=2) {
		q_21.pop();
		t1 = q_21.top();
	}
	pii t3 = q_23.top();
	while(bel[t3.second]!=2) {
		q_23.pop();
		t3 = q_23.top();
	}
	int minn = min(to_1,min(to_3,min(t1.first,t3.first)));
	ans-=minn;

	if(to_1 == minn) {
		bel[i] = 1;
		sum[1]++;
		q_12.push({a[i][1]-a[i][2],i});
		q_13.push({a[i][1]-a[i][3],i});
		return;
	}
	if(to_3 == minn) {
		bel[i] = 3;
		sum[3]++;
		q_31.push({a[i][3]-a[i][1],i});
		q_32.push({a[i][3]-a[i][2],i});
		return;
	}
	if(t1.first == minn) {
		bel[t1.second] = 1;  //t1.first去1
		sum[1]++;
		bel[i] = 2;
		q_21.pop();

		q_12.push({a[t1.second][1]-a[t1.second][2],t1.second});
		q_13.push({a[t1.second][1]-a[t1.second][3],t1.second});

		q_21.push({a[i][2]-a[i][1],i});
		q_23.push({a[i][2]-a[i][3],i});
		return;
	}
	if(t3.first == minn) {
		bel[t3.second] = 3;
		sum[3]++;
		bel[i] = 2;

		q_23.pop();

		q_31.push({a[t3.second][3]-a[t3.second][1],t3.second});
		q_32.push({a[t3.second][3]-a[t3.second][2],t3.second});

		q_21.push({a[i][2]-a[i][1],i});
		q_23.push({a[i][2]-a[i][3],i});
		return;
	}
}


void solve3(int i) {
	if(sum[3]<lim) {
		sum[3]++;
		bel[i] = 3;
		ans+=a[i][3];
		q_31.push({a[i][3]-a[i][1],i});
		q_32.push({a[i][3]-a[i][2],i});
		return;
	}
	ans+=a[i][3];
	//移动别的
	int to_1 = a[i][3]-a[i][1];
	int to_2 = a[i][3]-a[i][2];
	pii t1 = q_31.top();
	while(bel[t1.second]!=3) {
		q_31.pop();
		t1 = q_31.top();
	}
	pii t2 = q_32.top();
	while(bel[t2.second]!=3) {
		q_32.pop();
		t2 = q_32.top();
	}
	int minn = min(to_1,min(to_2,min(t2.first,t1.first)));
	ans-=minn;

	if(to_1 == minn) {
		bel[i] = 1;
		sum[1]++;
		q_12.push({a[i][1]-a[i][2],i});
		q_13.push({a[i][1]-a[i][3],i});
		return;
	}
	if(to_2 == minn) {
		bel[i] =2;
		sum[2]++;
		q_21.push({a[i][2]-a[i][1],i});
		q_23.push({a[i][2]-a[i][3],i});
		return;
	}
	if(t1.first == minn) {
		bel[t1.second] = 1;  //t1.first去1
		sum[1]++;
		bel[i] = 3;
		q_31.pop();

		q_12.push({a[t1.second][1]-a[t1.second][2],t1.second});
		q_13.push({a[t1.second][1]-a[t1.second][3],t1.second});

		q_31.push({a[i][3]-a[i][1],i});
		q_32.push({a[i][3]-a[i][2],i});
		return;
	}
	if(t2.first == minn) {
		bel[t2.second] = 2;
		sum[2]++;
		bel[i] = 3;

		q_32.pop();

		q_21.push({a[t2.second][2]-a[t2.second][1],t2.second});
		q_23.push({a[t2.second][2]-a[t2.second][3],t2.second});

		q_31.push({a[i][3]-a[i][1],i});
		q_32.push({a[i][3]-a[i][2],i});
		return;
	}
}

void work() {
	for(register int  i = 1; i<=n; i++) {
		int maxx = a[i][1];
		int st = 1;
		for(register int  j = 2; j<=3; j++) {
			if(maxx<a[i][j]) {
				maxx = a[i][j];
				st = j;
			}
		}

		if(st == 1) {
			solve1(i);
		} else if(st == 2) {
			solve2(i);
		} else {
			solve3(i);
		}

	}

}

void init() {
	while(!q_12.empty()) q_12.pop();
	while(!q_13.empty()) q_13.pop();
	while(!q_21.empty()) q_21.pop();
	while(!q_23.empty()) q_23.pop();
	while(!q_31.empty()) q_31.pop();
	while(!q_32.empty()) q_32.pop();
	for(int i = 1; i<=n; i++) bel[i] = 0;
	sum[1] =sum[2] = sum[3] = 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		init();
		lim = n/2;
		ans = 0;
		for(register int i = 1; i<=n; i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		work();
		printf("%d\n",ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
