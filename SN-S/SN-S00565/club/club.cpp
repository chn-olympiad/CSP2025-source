#include<bits/stdc++.h>
using namespace std;
struct myd{
	int bm1,bm2,bm3;
}a[120000];
int b[5];
bool cmp1(myd x,myd y){
	if(x.bm2==y.bm2)return x.bm1<=y.bm1;
	return x.bm2>y.bm2;
}
bool cmp2(myd x,myd y){
	if(x.bm3==y.bm3)return x.bm2<=y.bm2;
	return x.bm3>y.bm3;
}
bool cmp3(myd x,myd y){
	if(x.bm1==y.bm1)return x.bm3<=y.bm3;
	return x.bm1>y.bm1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].bm1>>a[i].bm2>>a[i].bm3;
			
			if(a[i].bm1>a[i].bm2&&a[i].bm1>a[i].bm3)b[1]++;
			else if(a[i].bm2>a[i].bm1&&a[i].bm2>a[i].bm3)b[2]++;
			else b[3]++;
			ans+=max(max(a[i].bm1,a[i].bm2),a[i].bm3);
		}
		
		while(b[1]>n/2){
			sort(a+1,a+1+n,cmp1);
			ans=ans-a[1].bm1+a[1].bm2;
			b[1]--;
		}
		while(b[2]>n/2){
			sort(a+1,a+1+n,cmp2);
			ans=ans-a[1].bm2+a[1].bm3;
			b[2]--;
		}
		while(b[3]>n/2){
			sort(a+1,a+1+n,cmp3);
			ans=ans-a[1].bm3+a[1].bm1;
			b[3]--;
		}
		cout<<ans<<endl;
		
		b[1]=0;
		b[2]=0;
		b[3]=0;
		for(int i=1;i<=n;i++){
			a[i].bm1=0;
			a[i].bm2=0;
			a[i].bm3=0;	
		}
	}
	
	
	
	return 0;
}

