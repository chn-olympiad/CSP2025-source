#include <bits/stdc++.h>
using namespace std;
struct school {
	int sch1;
	int sch2;
	int sch3;
	int max123;
};
int t;
int n;
school q[200050];
bool cmp(school a,school b) {
	if(a.max123==b.max123) {
		int sa,sb;
		if(a.max123==1) {
			sa=a.sch1-max(a.sch2,a.sch3);
			sb=b.sch1-max(b.sch2,b.sch3);
			return sa<sb;
		}
		if(a.max123==2) {
			sa=a.sch2-max(a.sch1,a.sch3);
			sb=b.sch2-max(b.sch1,b.sch3);
			return sa<sb;
		}
		if(a.max123==3) {
			sa=a.sch3-max(a.sch2,a.sch1);
			sb=b.sch3-max(b.sch2,b.sch1);
			return sa<sb;
		}
	}
	return a.max123<b.max123;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		long long int sum_max=0;
		int h=0;

		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			int ans_max=0,ij;
			scanf("%d",&q[i].sch1);
			if(ans_max<q[i].sch1) {
				ans_max=q[i].sch1;
				ij=1;
			}
			scanf("%d",&q[i].sch2);
			if(ans_max<q[i].sch2) {
				ans_max=q[i].sch2;
				ij=2;
			}
			scanf("%d",&q[i].sch3);
			if(ans_max<q[i].sch3) {
				ans_max=q[i].sch3;
				ij=3;
			}
			q[i].max123=ij;
			sum_max+=ans_max;
		}
		sort(q+1,q+1+n,cmp);
		int school1=1;
		int school2=-1;
		int school3=-1;
		int sch=1;
		for(int i=1; i<=n; i++) {
			if(q[i].max123!=sch&&q[i].max123==2) {
				sch=q[i].max123;
				school2=i;
			}
			if(q[i].max123!=sch&&q[i].max123==3) {
				if(school2==-1) school2=i;
				sch=q[i].max123;
				school3=i;
			}
		}
		if(school2==-1) {
			school2=n+1;

		}
		if(school3==-1) {
			school3=n+1;
		}
		if(school2-school1>n/2) {
			for(int i=school1; i<=school2-1-n/2; i++) {
				sum_max-=q[i].sch1-max(q[i].sch2,q[i].sch3);
			}
		}

		if(school3-school2>n/2) {
			for(int i=school2; i<=school3-1-n/2; i++) {
				sum_max-=q[i].sch2-max(q[i].sch1,q[i].sch3);
			}
		}

		if(n+1-school3>n/2) {
			for(int i=school3; i<=n-n/2; i++) {
				sum_max-=q[i].sch3-max(q[i].sch1,q[i].sch2);
			}
		}

		cout<<sum_max<<endl;
	}
	return 0;
}

