#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
struct node {
	int A,B,C,dt;
} a[N];
bool check1() {
	for(int i=1; i<=n; i++) {
		if(a[i].B!=0||a[i].C!=0) {
			return 0;
		}
	}
	return 1;
}
bool check2() {
	for(int i=1; i<=n; i++) {
		if(a[i].C!=0) {
			return 0;
		}
	}
	return 1;
}
bool cmp1(node p,node q) {
	return p.A>q.A;
}
bool cmp2(node p,node q) {
	return p.dt>q.dt;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].A>>a[i].B>>a[i].C;
		}
		if(check1()) {
			sort(a+1,a+1+n,cmp1);
			int sum1=0;
			for(int i=1; i<=n/2; i++) {
				sum1+=a[i].A;
			}
			cout<<sum1<<'\n';
		} else if(n==2) {
			int a1=a[1].A+a[2].B;
			int a2=a[1].A+a[2].C;
			int a3=a[1].B+a[2].A;
			int a4=a[1].B+a[2].C;
			int a5=a[1].C+a[2].A;
			int a6=a[1].C+a[2].B;
			cout<<max(a1,max(a2,max(a3,max(a4,max(a5,a6)))))<<'\n';
		} else if(check2()) {
			int sum2=0;
			for(int i=1; i<=n; i++) {
				a[i].dt=a[i].A-a[i].B;
			}
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				sum2+=a[i].A;
			}
			for(int i=n/2+1;i<=n;i++){
				sum2+=a[i].B;
			}
			cout<<sum2<<'\n';
		}
	}
	return 0;
}

