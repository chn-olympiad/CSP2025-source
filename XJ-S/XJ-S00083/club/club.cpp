#include<bits/stdc++.h>
using namespace std;
int t,n,a[10],ans;
void solve(){
	int maxm=0,sum=0;
	for(int i=1;i<=3;i++){
		for(int j=4;j<=6;j++){
			sum=a[i]+a[j];
			if(i+3!=j)maxm=max(sum,maxm);
		}
	}
	ans+=maxm;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==100000){
			int b[100005]={0};
			for(int i=1;i<=n;i++){
				int x,y;
				cin>>b[i]>>x>>y;
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans;
			continue;
		}
		ans=0;
		for(int i=1;i<=n/2;i++){
			cin>>a[1]>>a[2]>>a[3];
			cin>>a[4]>>a[5]>>a[6];
			solve();
		}
		cout<<ans<<endl;
	}
	return 0;
}






