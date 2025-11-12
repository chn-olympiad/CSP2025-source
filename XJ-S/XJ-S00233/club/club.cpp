#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010],b[100010],c[1000010],sum,sum1,cnt1=0,cnt2=0,cnt3=0,flag1,flag2,flag3;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		sum=0;
		cnt1=n/2;
		cnt2=n/2;
		cnt3=n/2;
		flag1=0,flag2=0,flag3=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0) flag1=1;
			if(a[i]!=0 || c[i]!=0) flag2=1;
			if(a[i]!=0 || b[i]!=0) flag3=1;
		}
		//ÌØÊâÊı¾İ 
		if(flag1==0) {
			sort(a+1,a+1+n,cmp);
			int z=1;
			sum+=a[1];
			if(cnt1>0) {
				z++;
				sum+=a[z];
				cnt1--;
			}
			cout<<sum<<endl;
			continue;
		}
		else if(flag2==0) {
			sort(b+1,b+1+n,cmp);
			int z=1;
			sum+=b[1];
			if(cnt2>0) {
				z++;
				sum+=b[z];
				cnt2--;
			}
			cout<<sum<<endl;
			continue;
		}
		else if(flag3==0) {
			sort(c+1,c+1+n,cmp);
			int z=1;
			sum+=c[1];
			if(cnt3>0) {
				z++;
				sum+=c[z];
				cnt3--;
			}
			cout<<sum<<endl;
			continue;			
		}
		//
		sum=0;
		cnt1=n/2;
		cnt2=n/2;
		cnt3=n/2;
		for(int i=1; i<=n; i++) {
			if(a[i]>c[i] && a[i]>b[i]) {
				if(cnt1>0) {
					sum+=a[i];
					cnt1--;
				}
			}
			if(b[i]>c[i] && b[i]>a[i]) {
				if(cnt2>0) {
					sum+=b[i];
					cnt2--;
				}
			}
			if(c[i]>a[i] && c[i]>b[i]) {
				if(cnt3>0) {
					sum+=c[i];
					cnt3--;
				}
			}
		}
		//
		sum1=0;
		cnt1=n/2;
		cnt2=n/2;
		cnt3=n/2;
		for(int i=n; i>=1; i--) {
			if(a[i]>c[i] && a[i]>b[i]) {
				if(cnt1>0) {
					sum1+=a[i];
					cnt1--;
				} else {
					if(c[i]>b[i]){
						sum+=c[i];
						cnt3--; 
					} else {
						sum+=b[i];
						cnt2--;
					}
				}
			}
			if(b[i]>c[i] && b[i]>a[i]) {
				if(cnt2>0) {
					sum1+=b[i];
					cnt2--;
				} else {
					if(c[i]>a[i]){
						sum+=c[i];
						cnt3--;
					} else {
						sum+=a[i];
						cnt1--;
					}
				}
			}
			if(c[i]>a[i] && c[i]>b[i]) {
				if(cnt3>0) {
					sum1+=c[i];
					cnt3--;
				} else {
					if(a[i]>b[i]){
						sum+=a[i];
						cnt1--;
					} else {
						sum+=b[i];
						cnt2--;
					}
				}
			}
		}
		int ans=max(sum,sum1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

1
4
2 0 0
1 0 0
2 0 0
1 0 0

4
*/
