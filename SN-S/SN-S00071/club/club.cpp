#include<bits/stdc++.h> 
using namespace std;
const int N = 3e3 + 8;
int t, n, maxn, tot;
int a1[N], a2[N], a3[N], manu[N], ma1, ma2, ma3, cinu[N], cha[N];
bool vis[N];
struct Stu{
	int a1, a2, a3;
}stu[N];

bool cmp1(Stu x, Stu y) {
	return x.a1 > y.a1;
}

bool cmp2(Stu x, Stu y) {
	return x.a2 > y.a2;
}

bool cmp3(Stu x, Stu y) {
	return x.a3 > y.a3;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--) {
		tot=0;
		cin>>n;
		if(n == 2) {
			for(int i=1; i<=3; i++) {
				cin>>a1[i];
			}
			for(int i=1; i<=3; i++) {
				cin>>a2[i];
			}
			for(int i=1; i<=3; i++) {
				for(int j=1; j<=3; j++) {
					if(i == j) continue;
					tot = max(tot, a1[i]+a2[j]);
				}
			}
			cout<<tot<<endl;
			for(int i=1; i<=3; i++) {
				a1[i]=0;
				a2[i]=0;
			}
		}else if(n > 2) {
			for(int i=1; i<=n; i++) {
				cin>>stu[i].a1>>stu[i].a2>>stu[i].a3;
				if(stu[i].a1 < stu[i].a2) {
					if(stu[i].a2 < stu[i].a3) {
						manu[i] = 3;
						ma3++;
						cinu[i] = 2;
					}else {
						manu[i] = 2;
						ma2++;
						if(stu[i].a1 < stu[i].a3) {
							cinu[i] = 3;
						}else {
							cinu[i] = 1;
						}
					}
				}else {
					if(stu[i].a1 < stu[i].a3) {
						manu[i] = 3;
						ma3++;
						cinu[i] = 1;
					}else {
						manu[i] = 1;
						ma1++;
						if(stu[i].a2 < stu[i].a3) {
							cinu[i] = 3;
						}else {
							cinu[i] = 2;
						}
					}
				}
			}
			
			if(ma1 <= n/2 && ma2 <= n/2 && ma3 <= n/2) {
				for(int i=1; i<=n; i++) {
					if(manu[i] == 1) tot += stu[i].a1;
					else if(manu[i] == 2) tot += stu[i].a2;
					else if(manu[i] == 3) tot += stu[i].a3;
				}
			}else {
				if(ma1 > n/2) {
					int maidx=0, ciidx=0;
					for(int i=1; i<=n; i++) {
						if(manu[i] == 1) {
							if(manu[i] == 1) maidx = stu[i].a1;
							else if(manu[i] == 2) maidx = stu[i].a2;
							else if(manu[i] == 3) maidx = stu[i].a3;
							if(cinu[i] == 1) ciidx = stu[i].a1;
							else if(cinu[i] == 2) ciidx = stu[i].a2;
							else if(cinu[i] == 3) ciidx = stu[i].a3;
							cha[i] = maidx - ciidx;
						}
					}
					sort(stu+1, stu+n+1, cmp1);
					sort(cha+1, cha+n+1);
					for(int i=1; i<=n; i++) {
						if(manu[i] == 1) tot += stu[i].a1;
						if(manu[i] == 2) tot += stu[i].a2;
						if(manu[i] == 3) tot += stu[i].a3;
					}
					int idx = ma1 - n/2;
//					cout<<ma1<<' '<<n/2<<endl;
					for(int i=1; i<=idx; i++) {
						tot -= cha[i];
					}
				}
				if(ma2 > n/2) {
					int maidx=0, ciidx=0;
					for(int i=1; i<=n; i++) {
						if(manu[i] == 2) {
							if(manu[i] == 1) maidx = stu[i].a1;
							else if(manu[i] == 2) maidx = stu[i].a2;
							else if(manu[i] == 3) maidx = stu[i].a3;
							if(cinu[i] == 1) ciidx = stu[i].a1;
							else if(cinu[i] == 2) ciidx = stu[i].a2;
							else if(cinu[i] == 3) ciidx = stu[i].a3;
							cha[i] = maidx - ciidx;
						}
					}
					sort(stu+1, stu+n+1, cmp1);
					sort(cha+1, cha+n+1);
					for(int i=1; i<=n; i++) {
						if(manu[i] == 1) tot += stu[i].a1;
						if(manu[i] == 2) tot += stu[i].a2;
						if(manu[i] == 3) tot += stu[i].a3;
					}
					int idx = ma2 - n/2;
//					cout<<ma2<<' '<<n/2<<endl;
					for(int i=1; i<=idx; i++) {
						tot -= cha[i];
					}
				}
				if(ma3 > n/2){
					int maidx=0, ciidx=0;
					for(int i=1; i<=n; i++) {
						if(manu[i] == 3) {
							if(manu[i] == 1) maidx = stu[i].a1;
							else if(manu[i] == 2) maidx = stu[i].a2;
							else if(manu[i] == 3) maidx = stu[i].a3;
							if(cinu[i] == 1) ciidx = stu[i].a1;
							else if(cinu[i] == 2) ciidx = stu[i].a2;
							else if(cinu[i] == 3) ciidx = stu[i].a3;
							cha[i] = maidx - ciidx;
						}
					}
					sort(stu+1, stu+n+1, cmp1);
					sort(cha+1, cha+n+1);
					for(int i=1; i<=n; i++) {
						if(manu[i] == 1) tot += stu[i].a1;
						if(manu[i] == 2) tot += stu[i].a2;
						if(manu[i] == 3) tot += stu[i].a3;
					}
					int idx = ma3 - n/2;
//					cout<<ma3<<' '<<n/2<<endl;
					for(int i=1; i<=idx; i++) {
						tot -= cha[i];
					}
				}
			}
			
			cout<<tot<<endl;
			for(int i=1; i<=n; i++) {
				a1[i] = 0;
				a2[i] = 0;
				vis[i] = 0;
			}
			ma1 = 0;
			ma2 = 0;
			ma3 = 0;
		}
	}
		
	
	
	
	return 0;
}

