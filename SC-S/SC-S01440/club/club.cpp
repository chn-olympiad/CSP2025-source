#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,t;
unsigned int lim;
struct Worker {
	int a[4];
	int best; // -1,0,1 referred to which is the biggest
	
	bool compareTo (const Worker& other) {
		if(best == other.best) {
			if(a[3] == other.a[3]) {
				if(a[2] == other.a[2]) {
					return a[1] > other.a[1];
				}
				return a[2] > other.a[2];
			}
			return a[3] > other.a[3];
		}
		return best < other.best;
	}
	
	void process() {
		if(a[1] >= a[2] && a[1] >= a[3]) best = 1;
		else if(a[2] >= a[1] && a[2] >= a[3]) best = 2;
		else if(a[3] >= a[1] && a[3] >= a[3]) best = 3;
	}
}w[N];
int sense[4];

bool cmp(Worker& a,Worker& b) {
	return a.compareTo(b); 
	// element "a" processed as the first priority
	// element "b" processed as the second priority
	// element "c" processed as the third priority
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--) {
		cin>>n;
		lim = n/2;
		bool cut1=true,cut2=true;
		w[0].best = INT_MIN;
		for(int i=1;i<=n;i++) {
			cin>>w[i].a[1]>>w[i].a[2]>>w[i].a[3];
			if(w[i].a[2] || w[i].a[3]) cut1 = false;
			if(w[i].a[3]) cut2 = false;
			w[i].process();
		}
		int ans=0;
		if(cut1) {
			sort(w+1,w+n+1,cmp);
			for(unsigned int i=1;i<=lim;++i) {
				ans += w[i].a[1];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(cut2) {
			// i dont know
		}
		
		sort(w+1,w+n+1,cmp);
		
//		printf("\n");
//		for(int i=1;i<=n;i++) {
//			printf("%d %d %d  %d\n",w[i].a[1],w[i].a[2],w[i].a[3],w[i].best);
//		}
		
		unsigned int cnt=1;
		int ptr=1;
		sense[1] = sense[2] = sense[3] = 0;
		for(int i=1;i<=n;i++) {
			// 如果这个 club 的人数超过 n/2 了
			if(cnt > lim) {
				cnt = 1;
				++ptr;
			}
			
			// 如果这个人好感最高的 club 不是当前 club
			if(w[i].best > w[i-1].best && w[i].best != ptr) {
				ptr = w[i].best;
			}
			
			sense[ptr] += w[i].a[ptr];
			++cnt;
			
//			printf("current_club : %d , population : %d\n",ptr,cnt-1);
		}
		cout<<sense[1]+sense[2]+sense[3]<<"\n";
	}
	return 0;
}