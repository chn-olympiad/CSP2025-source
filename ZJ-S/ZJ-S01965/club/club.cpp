#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
	int val1,val2,val3,Max,Max2,k;
}a[MAXN];
bool cmp(node a,node b){
	return (a.Max-a.Max2)<(b.Max-b.Max2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnt1=0,cnt2=0,cnt3=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].val1>>a[i].val2>>a[i].val3;
		}
		for(int i=1;i<=n;i++){
			if(a[i].val1>=a[i].val2 && a[i].val1>=a[i].val3){
				a[i].Max=a[i].val1;
				a[i].k=1;
				if(a[i].val2>=a[i].val3){
					a[i].Max2=a[i].val2;
				}else{
					a[i].Max2=a[i].val3;
				}
				cnt1++;
				ans+=a[i].val1;
			}else if(a[i].val2>=a[i].val1 && a[i].val2>=a[i].val3){
				a[i].Max=a[i].val2;
				a[i].k=2;
				if(a[i].val1>=a[i].val3){
					a[i].Max2=a[i].val1;
				}else{
					a[i].Max2=a[i].val3;
				}
				cnt2++;
				ans+=a[i].val2;
			}else{
				a[i].Max=a[i].val3;
				a[i].k=3;
				if(a[i].val1>=a[i].val2){
					a[i].Max2=a[i].val1;
				}else{
					a[i].Max2=a[i].val2;
				}
				cnt3++;
				ans+=a[i].val3;
			}
		}
		sort(a+1,a+n+1,cmp);
		/*for(int i=1;i<=n;i++){
			cout<<a[i].Max<<" "<<a[i].Max2<<endl;
		}*/
		if(cnt1>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].k==1){
					ans-=(a[i].Max-a[i].Max2);
					cnt1--;
				}
				if(cnt1==n/2){
					break;
				}
			}
		}else if(cnt2>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].k==2){
					ans-=(a[i].Max-a[i].Max2);
					cnt2--;
				}
				if(cnt2==n/2){
					break;
				}
			}
		}else if(cnt3>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].k==3){
					ans-=(a[i].Max-a[i].Max2);
					cnt3--;
				}
				if(cnt3==n/2){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
4
2 0 0
3 0 0
4 0 0
5 0 0
*/
