#include<bits/stdc++.h>
using namespace std;
long long t,n,maxn,sum,flag1,flag2,flag3,ans,cnt[5],k1[100005],k2[100005],k3[100005],arr[100005][5];
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long x){
	if(x==n+1){
		maxn=max(maxn,sum);
		return;
	}
	for(long long i=1;i<=3;i++){
		if(cnt[i]+1>n/2) continue;
		cnt[i]++;
		sum+=arr[x][i];
		dfs(x+1);
		sum-=arr[x][i];
		cnt[i]--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxn=0;
		sum=0;
		ans=0;
		flag1=0;
		flag2=0;
		flag3=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(long long i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			if(arr[i][1]!=0 or arr[i][2]!=0) flag1=1;
			if(arr[i][1]!=0 or arr[i][3]!=0) flag2=1;
			if(arr[i][2]!=0 or arr[i][3]!=0) flag3=1;
			if(flag1==0) k1[i]=arr[i][3];
			if(flag2==0) k2[i]=arr[i][2];
			if(flag3==0) k3[i]=arr[i][1];
		}
		if(flag1==0){
			sort(k1+1,k1+1+n,cmp);
			for(long long i=1;i<=n/2;i++) ans+=k1[i];
			cout<<ans<<endl;
			continue;
		}
		if(flag2==0){
			sort(k2+1,k2+1+n,cmp);
			for(long long i=1;i<=n/2;i++) ans+=k2[i];
			cout<<ans<<endl;
			continue;
		}
		if(flag3==0){
			sort(k3+1,k3+1+n,cmp);
			for(long long i=1;i<=n/2;i++) ans+=k3[i];
			cout<<ans<<endl;
			continue;
		}
		dfs(1);
		cout<<maxn<<endl;
	}
	return 0;
}
