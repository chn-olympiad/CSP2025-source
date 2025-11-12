#include<bits/stdc++.h>
#define int long long
using namespace std;
struct qwer1 {
	int q,w1;
} d1[9999999];
struct qwer2 {
	int w,w2;
} d2[9999999];
struct qwer3 {
	int e,w3;
} d3[9999999];
int cmp1(qwer1 o,qwer1 p) {
	return o.w1<p.w1;
}
int cmp2(qwer2 o,qwer2 p) {
	return o.w2<p.w2;
}
int cmp3(qwer3 o,qwer3 p) {
	return o.w3<p.w3;
}
int n,cnt1,cnt2,cnt3,t,sum,ans1,ans2,ans3;
int a[9999999],b[9999999],c[9999999];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans1=0;
		ans2=0;
		ans3=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		sum=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(max(a[i]-b[i],a[i]-c[i])>max(max(b[i]-c[i],b[i]-a[i]),max(c[i]-a[i],c[i]-b[i]))) {
				cnt1++;
				d1[i].q=max(a[i]-b[i],a[i]-c[i]);
			} else {
				if(max(b[i]-a[i],b[i]-c[i])>max(max(a[i]-c[i],a[i]-b[i]),max(c[i]-b[i],c[i]-a[i]))) {
					cnt2++;
					d2[i].w=max(b[i]-a[i],b[i]-c[i]);
				} else {
					cnt3++;
					d3[i].e=max(c[i]-a[i],c[i]-b[i]);
				}
			}
		}
		sort(d1+1,d1+1+cnt1,cmp1);
		sort(d2+1,d2+1+cnt2,cmp2);
		sort(d3+1,d3+1+cnt3,cmp3);
		while(n!=0) {
			n--;
			if(d1[cnt1].q>max(d2[cnt1].w,d3[cnt1].e));
			{
				if(ans1>n/2)
					sum+=min(a[d1[cnt1].w1]-b[d1[cnt1].w1],a[d1[cnt1].w1]-c[d1[cnt1].w1]);
				else {
					sum+=d1[cnt1].q;
					ans1++;
				}
			}
			if(d2[cnt2].w>max(d3[cnt2].e,d1[cnt2].q)) {
				if(ans2>n/2)
					sum+=min(a[d2[cnt2].w2]-b[d2[cnt2].w2],a[d2[cnt2].w2]-c[d2[cnt2].w2]);
				else {
					sum+=d2[cnt2].w;
					ans2++;
				}
			}
			if(d3[cnt3].e>max(d2[cnt3].w,d1[cnt3].q)) {
				if(ans3>n/2)
					sum+=min(a[d3[cnt3].w3]-b[d2[cnt3].w2],a[d2[cnt3].w2]-c[d2[cnt3].w2]);
				else {
					sum+=d3[cnt3].e;
					ans3++;
				}
			}
		}
		cout<<sum;
	}
	return 0;																						 
}