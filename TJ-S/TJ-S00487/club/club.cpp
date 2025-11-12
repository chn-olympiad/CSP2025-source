#include <bits/stdc++.h>
using namespace std;
long long t,n,cnt1=1,cnt2=1,cnt3=1,ans,maxx1=-1e9,maxx2=-1e9,maxx3=-1e9;
struct node{
	long long s1,s2,s3;
	bool f;
}a[100005];
int maxx(int x){
	if(max(a[x].s1,max(a[x].s2,a[x].s3))==a[x].s1){
		return a[x].s1;
	}
	else if(max(a[x].s1,max(a[x].s2,a[x].s3))==a[x].s2){
		return a[x].s2;
	}
	else{
		return a[x].s3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt1=0,cnt2=0,cnt3=0;
		maxx1=-1e9,maxx2=-1e9,maxx3=-1e9;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			a[i].f=0;
			maxx1=max(maxx1,a[i].s1);
			maxx2=max(maxx2,a[i].s2);
			maxx3=max(maxx3,a[i].s3);
		}
		ans+=maxx1;
		ans+=maxx2;
		ans+=maxx3;
		for(int i=1;i<=n;i++){
			if(a[i].s1==maxx1){
				a[i].f=1;
				maxx1=-1;
			}
			else if(a[i].s2==maxx2){
				a[i].f=1;
				maxx2=-1;
			}
			else if(a[i].s3==maxx3){
				a[i].f=1;
				maxx3=-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(maxx(i)==a[i].s1&&!a[i].f&&cnt1<n/2){
				ans+=a[i].s1;
				a[i].f=1;
				cnt1++;
			}
			else if(maxx(i)==a[i].s2&&!a[i].f&&cnt2<n/2){
				ans+=a[i].s2;
				a[i].f=1;
				cnt2++;
			}
			else if(cnt3<n/2&&!a[i].f){
				ans+=a[i].s3;
				a[i].f=1;
				cnt3++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
