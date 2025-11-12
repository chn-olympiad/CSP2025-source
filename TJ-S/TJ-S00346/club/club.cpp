#include<bits/stdc++.h>
using namespace std;
int n,f1[100005],f2[100005],f3[100005];
struct node{
	int l1,l2,l3;
}a[100005];
void solve(){
	memset(a,0,sizeof(a));
	bool A=1,B=1;
	long long sum=0,r1=0,r2=0,r3=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l1>>a[i].l2>>a[i].l3;
		if(a[i].l1>=a[i].l2&&a[i].l1>=a[i].l3){
			sum+=a[i].l1,r1++;
			f1[r1]=min(a[i].l1-a[i].l2,a[i].l1-a[i].l3);
		}
		else if(a[i].l2>=a[i].l1&&a[i].l2>=a[i].l3){
			sum+=a[i].l2,r2++;
			f2[r2]=min(a[i].l2-a[i].l1,a[i].l2-a[i].l3);
		}
		else if(a[i].l3>=a[i].l2&&a[i].l3>=a[i].l1){
			sum+=a[i].l3,r3++;
			f3[r3]=min(a[i].l3-a[i].l2,a[i].l3-a[i].l1);
		}
	}
	if(r1<=n/2&&r2<=n/2&&r3<=n/2){cout<<sum<<endl;return;}
	if(r1>n/2){
		sort(f1+1,f1+r1+1);
		for(int i=1;i<=r1-n/2;i++){
			sum-=f1[i];
		}
		cout<<sum<<endl;
		return;
	}
	if(r2>n/2){
		sort(f2+1,f2+r2+1);
		for(int i=1;i<=r2-n/2;i++){
			sum-=f2[i];
		}
		cout<<sum<<endl;
		return;
	}
	if(r3>n/2){
		sort(f3+1,f3+r3+1);
		for(int i=1;i<=r3-n/2;i++){
			sum-=f3[i];
		}
		cout<<sum<<endl;
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
}
