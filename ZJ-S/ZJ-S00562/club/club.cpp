//by snakeMC
//now:UAC 0pts  tp a ~5pts
#include<bits/stdc++.h>
using namespace std;
int n,t;
struct peo {
	int a[3];
} a[100010];
struct bm {
	priority_queue<pair<int,int> > b[2];
	int cnt;
} b[3];

bool cmp1(peo x,peo y) {
	return x.a[0]>y.a[0];
}
//tp

bool pop[100010];
int s=0;
int cnt0,cnt1,cnt2;
int to1,to2,to1i,to2i;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	bool f1=true,f2=true;
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		s=0;
		for(int i=0; i<3; i++) {
			for(int j=0; j<2; j++) {
				while(!b[i].b[j].empty())b[i].b[j].pop();
			}
			b[i].cnt=0;
		}
		for(int i=0; i<n; i++) {
			cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
			t=max(a[i].a[0],max(a[i].a[1],a[i].a[2]));

			if(a[i].a[1]!=0)f1=false;
			if(a[i].a[2]!=0)f2=false;
			//tp

			if(t==a[i].a[0]) {
				b[0].b[0].push(make_pair(a[i].a[1]-a[i].a[0],i));
				b[0].b[1].push(make_pair(a[i].a[2]-a[i].a[0],i));
				b[0].cnt++;
				s+=a[i].a[0];
			} else if(t==a[i].a[1]) {
				b[1].b[0].push(make_pair(a[i].a[0]-a[i].a[1],i));
				b[1].b[1].push(make_pair(a[i].a[2]-a[i].a[1],i));
				b[1].cnt++;
				s+=a[i].a[1];
			} else if(t==a[i].a[2]) {
				b[2].b[0].push(make_pair(a[i].a[0]-a[i].a[2],i));
				b[2].b[1].push(make_pair(a[i].a[1]-a[i].a[2],i));
				b[2].cnt++;
				s+=a[i].a[2];
			}
		}
		if(f1) {
			sort(a,a+n,cmp1);
			int cnt=0;
			for(int i=0; i<n/2; i++) {
				cnt+=a[i].a[1];
			}
			cout<<cnt<<endl;
			continue;
		}
//		if(f2) {
//			priority_queue<int> pq1,pq2;
//			int s=0,cnt1=0,cnt2=0;
//			for(int i=0; i<n; i++) {
//				if(a[i].a[0]>a[i].a[1]) {
//					pq2.push(a[i].a[1]-a[i].a[0]);
//					s+=a[i].a[0];
//					cnt1++;
//				} else {
//					pq1.push(a[i].a[0]-a[i].a[1]);
//					s+=a[i].a[1];
//					cnt2++;
//				}
//			}
//			while(cnt1>n/2) {
//
//			}
//			continue;
//		}
		while(b[0].cnt>n/2) {
			while(pop[b[0].b[0].top().second])b[0].b[0].pop();
			while(pop[b[0].b[1].top().second])b[0].b[1].pop();
			to1=b[0].b[0].top().first;
			to2=b[0].b[1].top().first;
			to1i=b[0].b[0].top().second;
			to2i=b[0].b[1].top().second;
			if(to1>to2||f2) { //0->1
				b[0].b[0].pop();
				s+=to1;
				pop[to1i]=true;
			} else { //0->2
				b[0].b[1].pop();
				s+=to2;
				pop[to2i]=true;
			}
			b[0].cnt--;
		}
		while(b[1].cnt>n/2) {
			while(pop[b[1].b[0].top().second])b[1].b[0].pop();
			while(pop[b[1].b[1].top().second])b[1].b[1].pop();
			to1=b[1].b[0].top().first;
			to2=b[1].b[1].top().first;
			to1i=b[1].b[0].top().second;
			to2i=b[1].b[1].top().second;
			if(to1>to2||f2) { //1->0
				b[1].b[0].pop();
				pop[to1i]=true;
				s+=to1;
			} else { //1->2
				b[0].b[1].pop();
				pop[to2i]=true;
				s+=to2;
			}
			b[1].cnt--;
		}
		while(b[2].cnt>n/2) {
			while(pop[b[2].b[0].top().second])b[2].b[0].pop();
			while(pop[b[2].b[1].top().second])b[2].b[1].pop();
			to1=b[2].b[0].top().first;
			to2=b[2].b[1].top().first;
			to1i=b[2].b[0].top().second;
			to2i=b[2].b[1].top().second;
			if(to1>to2) { //2->0
				b[2].b[0].pop();
				pop[to1i]=true;
				s+=to1;
			} else { //2->1
				b[2].b[1].pop();
				pop[to2i]=true;
				s+=to2;
			}
			b[2].cnt--;
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
