//feropen
//freeopen
//1145141919810
//bilibili «Ô È¬‰“∂_ πÿ◊¢Œ“
//luogu Beijing_duck_

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

bool cmp(pair<int,int> p,pair<int,int>q) {
	return max(p.first,p.second)>max(q.first,q.second);
}
int numa,numb,numc,ans;
pair<int,int> A[maxn],B[maxn],C[maxn];
int n;
int t;
int a[maxn],b[maxn],c[maxn];

void slove() {
	for(int i=0; i<maxn; i++) {
		a[i]=b[i]=c[i]=0;
	}
	ans=numa=numb=numc=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i]>>c[i];
	}
	int tota=0,totb=0,totc=0;
	for(int i=1; i<=n; i++) {
		int res=max({a[i],b[i],c[i]});
		ans+=res,a[i]-=res,b[i]-=res,c[i]-=res;
		if(a[i]==0) {
			numa++;
			A[++tota]= {b[i],c[i]};
		} else if(b[i]==0) {
			numb++;
			B[++totb]= {a[i],c[i]};
		} else {
			numc++;
			C[++totc]= {a[i],b[i]};
		}
	}
	if(max({numa,numb,numc})<=n/2) {
		cout<<ans<<"\n";
		return ;
	}
	if(numa>n/2) {
		sort(A+1,A+tota+1,cmp);
		int g=numa-n/2;
		for(int i=0; i<=g; i++) {
			ans+=max(A[i].first,A[i].second);
		}
		cout<<ans<<"\n";
		return ;
	} else if(numb>n/2) {
		sort(B+1,B+totb+1,cmp);
		int g=numb-n/2;
		for(int i=0; i<=g; i++) {
			ans+=max(B[i].first,B[i].second);
		}
		cout<<ans<<"\n";
		return ;
	} else if(numc>n/2) {
		sort(C+1,C+totc+1,cmp);
		int g=numc-n/2;
		for(int i=0; i<=g; i++) {
			ans+=max(C[i].first,C[i].second);
		}
		cout<<ans<<"\n";
		return ;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		slove();
	}
	return 0;
}
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/
