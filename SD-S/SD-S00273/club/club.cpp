#include <bits/stdc++.h>
#define w first
#define id second
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N=1e5+5;
const ll M=0x3f3f3f3f3f3f3f3f;
int n;
ll a[N][5],aa[N];
bool cmp(ll x,ll y){
	return x>y;
}
priority_queue <PLL,vector<PLL>,greater<PLL> > qa,qb,qc;
void solve(){
	cin>>n;
	bool A=0;
	for(int i=1;i<=n;i++){cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0||a[i][3]!=0)
		A=1;
	}	
	if(!A){
		for(int i=1;i<=n;i++){
			aa[i]=a[i][1];
		}
		sort(aa+1,aa+n+1,cmp);
		ll tot=0;
		for(int i=1;i<=n/2;i++){
			tot+=aa[i];
		}
		cout<<tot<<"\n";
		return;
	}
	while(!qa.empty())qa.pop();
	while(!qb.empty())qb.pop();
	while(!qc.empty())qc.pop();
	ll res=0;
	ll la=0,lb=0,lc=0;
	a[0][1]=a[0][2]=a[0][3]=M;
for(int i=1;i<=n;i++){
	ll mx=max({a[i][1],a[i][2],a[i][3]});
	if(a[i][1]==mx){
		if(la<n/2){
			res+=a[i][1];
			la++;
			qa.push({a[i][1],i});
		}else{
			ll idd=qa.top().id;
			if(a[i][1]-a[idd][1]+max(a[idd][2],a[idd][3])>=0){
				res=res+a[i][1]-a[idd][1]+max(a[idd][2],a[idd][3]);
				if(a[idd][2]>a[idd][3])lb++,qb.push({a[idd][2],idd});
				else lc++,qc.push({a[idd][3],idd});
				qa.pop();
				qa.push({a[i][1],i});
			}else if(a[i][2]>a[i][3]){
				res+=a[i][2];
				lb++;
				qb.push({a[i][2],i});
			}else{
				res+=a[i][3];
				lc++;
				qc.push({a[i][3],i});
			}
		}
	}
	else if(a[i][2]==mx){
		if(lb<n/2){
			res+=a[i][2];
			lb++;
			qb.push({a[i][2],i});
		}else{ll idd=qb.top().id;
			if(a[i][2]-a[idd][2]+max(a[idd][1],a[idd][3])>=0){
				res=res+a[i][2]-a[idd][2]+max(a[idd][1],a[idd][3]);
				if(a[idd][1]>a[idd][3])la++,qa.push({a[idd][1],idd});
				else lc++,qc.push({a[idd][3],idd});
				qb.pop();
				qb.push({a[i][2],i});
			}else if(a[i][1]>a[i][3]){
				res+=a[i][1];
				la++;
				qa.push({a[i][1],i});
			}else{
				res+=a[i][3];
				lc++;
				qc.push({a[i][3],i});
			}
		}
	}
	else{
		if(lc<n/2){
			res+=a[i][3];
			lc++;
			qc.push({a[i][3],i});
		}else{
			ll idd=qc.top().id;
			if(a[i][3]-a[idd][3]+max(a[idd][2],a[idd][1])>=0){
				res=res+a[i][3]-a[idd][3]+max(a[idd][2],a[idd][1]);
				if(a[idd][1]>a[idd][2])la++,qa.push({a[idd][1],idd});
				else lb++,qb.push({a[idd][2],idd});
				qc.pop();
				qc.push({a[i][3],i});
			}else if(a[i][1]>a[i][2]){
				res+=a[i][1];
				la++;
				qa.push({a[i][1],i});
			}else{
				res+=a[i][2];
				lb++;
				qb.push({a[i][2],i});
			}
		}
	}
}
	cout<<res<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve(); 
	}
	return 0;
}
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
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
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107

*/
