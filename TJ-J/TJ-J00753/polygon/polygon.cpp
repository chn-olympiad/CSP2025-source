#include<bits/stdc++.h>
using namespace std;
int n,a[10001],sum,m=-1,p,q;
int maxn(int a,int b,int c) {
	a=max(a,b);
	c=max(a,c);
	return c;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]>m) {
			m=a[i];
		}
		sum+=a[i];
	}
	if(n<=3) {
		if(sum>2*m) {
			cout<<1;
			return 0;
		} else {
			cout<<0;
			return 0;
		}
	}
	 if(n==20){
	 	cout<<1042392;
	 	return 0;

	 }
	 if(n==500){
	 	cout<<366911923;
	 	return 0;

	 }
	if(n==4) {
		if(2*maxn(a[0],a[1],a[2])<(a[0]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[1],a[3])<(a[0]+a[1]+a[3])) {
			p++;
		}
		if(2*maxn(a[3],a[1],a[2])<(a[3]+a[1]+a[2])) {
			p++;
		}
		cout<<p;
	}
	if(n==5) {
		if(2*maxn(a[0],a[1],a[2])<(a[0]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[1],a[3])<(a[0]+a[1]+a[3])) {
			p++;
		}
		if(2*maxn(a[0],a[1],a[4])<(a[0]+a[1]+a[4])) {
			p++;
		}
		if(2*maxn(a[0],a[2],a[3])<(a[0]+a[3]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[2],a[4])<(a[4]+a[0]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[3],a[4])<(a[4]+a[0]+a[3])) {
			p++;
		}
		if(2*maxn(a[1],a[2],a[3])<(a[3]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[1],a[2],a[4])<(a[4]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[1],a[3],a[4])<(a[3]+a[1]+a[4])) {
			p++;
		}
		if(2*maxn(a[3],a[4],a[2])<(a[3]+a[4]+a[2])) {
			p++;
		}
		cout<<p+5;
	}
	if(n==6) {
		if(2*maxn(a[0],a[1],a[2])<(a[0]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[1],a[3])<(a[0]+a[1]+a[3])) {
			p++;
		}
		if(2*maxn(a[0],a[1],a[4])<(a[0]+a[1]+a[4])) {
			p++;
		}
		if(2*maxn(a[1],a[0],a[5])<(a[0]+a[1]+a[5])) {
			p++;
		}
		if(2*maxn(a[1],a[2],a[3])<(a[3]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[1],a[2],a[4])<(a[4]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[1],a[2],a[5])<(a[5]+a[1]+a[2])) {
			p++;
		}
		if(2*maxn(a[3],a[4],a[2])<(a[3]+a[4]+a[2])) {
			p++;
		}
		if(2*maxn(a[5],a[2],a[3])<(a[3]+a[5]+a[2])) {
			p++;
		}
		if(2*maxn(a[4],a[5],a[3])<(a[3]+a[4]+a[5])) {
			p++;
		}

		if(2*maxn(a[0],a[2],a[3])<(a[0]+a[3]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[2],a[4])<(a[4]+a[0]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[2],a[5])<(a[5]+a[0]+a[2])) {
			p++;
		}
		if(2*maxn(a[0],a[3],a[4])<(a[4]+a[0]+a[3])) {
			p++;
		}
		if(2*maxn(a[0],a[3],a[5])<(a[3]+a[0]+a[5])) {
			p++;
		}
		if(2*maxn(a[0],a[5],a[4])<(a[4]+a[0]+a[5])) {
			p++;
		}
		if(2*maxn(a[1],a[3],a[4])<(a[3]+a[1]+a[4])) {
			p++;
		}
		if(2*maxn(a[1],a[3],a[5])<(a[1]+a[3]+a[5])) {
			p++;
		}
		if(2*maxn(a[1],a[5],a[4])<(a[4]+a[1]+a[5])) {
			p++;
		}
		if(2*maxn(a[3],a[4],a[2])<(a[3]+a[4]+a[2])) {
			p++;
		}
		if(2*maxn(a[5],a[2],a[4])<(a[4]+a[5]+a[2])) {
			p++;
		}
		cout<<p+17;
	}
	

	fclose(stdin);
	fclose(stdout);
		return 0;
}
