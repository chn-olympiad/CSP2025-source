#include<bits/stdc++.h>
using namespace std;
long long ans,n,t,cnt3,cnt1,cnt2,cnt[4];
struct node{
	int myd[4];
}a[100005];
void dfs(int dq,long long sum){
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)
		return;
	if(dq>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		sum+=a[dq].myd[i];
		cnt[i]++;
		dfs(dq+1,sum);
		sum-=a[dq].myd[i];
		cnt[i]--;
	}
	return;
}
bool cmp(node aa,node bb){
	return aa.myd[1]>bb.myd[1];
}
void solve2(){
	long long sum=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		sum+=a[i].myd[1];
	}
	cout<<sum<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);///
	cin>>t;
	while(t--){
		ans=0;
		cnt1=0,cnt2=0,cnt3=0;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].myd[1]>>a[i].myd[2]>>a[i].myd[3];
			if(a[i].myd[1]==0)cnt1++;
			if(a[i].myd[2]==0)cnt2++;
			if(a[i].myd[3]==0)cnt3++;
		}
		if(cnt2==n&&cnt3==n){
			solve2();
		}else if(cnt3==n){
			dfs(1,0);
			cout<<ans<<endl;
		}else{
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	
	return 0;
} 
