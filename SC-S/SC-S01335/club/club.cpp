#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n,ans,mem1,mem2,mem3;
array<int,3> a[100005];
void dfs(int now,int num){
	if(now==n+1){
		ans=max(ans,num);
		return ;
	}
	if(mem1<n/2){
		mem1++;
		dfs(now+1,num+a[now][0]);
		mem1--;
	}
	if(mem2<n/2){
		mem2++;
		dfs(now+1,num+a[now][1]);
		mem2--;
	}
	if(mem3<n/2){
		mem3++;
		dfs(now+1,num+a[now][2]);
	}
	return ;
}
int main(){
	fre("club");
	int _;
	cin>>_;
	while(_--){
		bool _1=1;
		ans=0,mem1=0,mem2=0,mem3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]!=0||a[i][2]!=0)_1=0;
		}
		if(_1){
			sort(a+1,a+n+1);
			int sum=0;
			for(int i=n;i>n/2;i--)sum+=a[i][0];
			cout<<sum<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}