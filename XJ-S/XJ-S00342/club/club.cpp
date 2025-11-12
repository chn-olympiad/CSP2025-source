#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a1,a2,a3;
	int jd,maxn;
	string s1,s2,s3;
}a[100001];
bool cmp(node x,node y){
	if (x.jd==y.jd){
		return x.maxn>y.maxn;
	}
	return x.jd>y.jd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int d1=0,d2=0,d3=0,ans=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if (a[i].a1>a[i].a2){
				if (a[i].a2>a[i].a3){
					a[i].s1="a1";
					a[i].s2="a2";
					a[i].s3="a3";
					a[i].jd=a[i].a1-a[i].a2;
					a[i].maxn=a[i].a1;
				}
				else if (a[i].a1<a[i].a3){
					a[i].s1="a3";
					a[i].s2="a1";
					a[i].s3="a2";
					a[i].jd=a[i].a3-a[i].a1;
					a[i].maxn=a[i].a3;
				}
				else {
					a[i].s1="a1";
					a[i].s2="a3";
					a[i].s3="a2";
					a[i].jd=a[i].a1-a[i].a3;
					a[i].maxn=a[i].a1;
				}
			}
			else {
				if (a[i].a2<a[i].a3){
					a[i].s1="a3";
					a[i].s2="a2";
					a[i].s3="a1";
					a[i].jd=a[i].a3-a[i].a2;
					a[i].maxn=a[i].a3;
				}
				else if (a[i].a1>a[i].a3){
					a[i].s1="a2";
					a[i].s2="a1";
					a[i].s3="a3";
					a[i].jd=a[i].a2-a[i].a1;
					a[i].maxn=a[i].a2;
				}
				else {
					a[i].s1="a2";
					a[i].s2="a3";
					a[i].s3="a1";
					a[i].jd=a[i].a2-a[i].a3;
					a[i].maxn=a[i].a2;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++){
			if (a[i].a1==a[i].maxn){
				if (d1<n/2){
					ans+=a[i].maxn;
					d1++;
				}
				else{
					if (a[i].s2=="a2"){
						ans+=a[i].a2;
						d2++;
					}
					else {
						ans+=a[i].a3;
						d3++;
					}
				}
			}
			else if (a[i].a2==a[i].maxn){
				if (d2<n/2){
					ans+=a[i].maxn;
					d2++;
				}
				else{
					if (a[i].s2=="a1"){
						ans+=a[i].a1;
						d1++;
					}
					else {
						ans+=a[i].a3;
						d3++;
					}
				}
			}
			else{
				if (d3<n/2){
					ans+=a[i].maxn;
					d3++;
				}
				else{
					if (a[i].s2=="a1"){
						ans+=a[i].a1;
						d1++;
					}
					else{
						ans+=a[i].a2 ;
						d2++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
