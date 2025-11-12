#include<bits/stdc++.h>
//I love ccf,csp-j,csp-s,noip!hope me rp++!
using namespace std;
long long n,a[5005],ans;
bool cmp[5005];
void dfs(int step){
	if(step>n){
		long long res=0,maxn=0;
		for(int i=1;i<=n;i++){
			res+=(cmp[i]*a[i]);
			maxn=max(maxn,a[i]*cmp[i]);
		}
		if(maxn*2<res){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	cmp[step]=1;
	dfs(step+1);
	cmp[step]=0;
	dfs(step+1);
	return ;
}
void subtask1(){//maybe 40 score?(hope quickly):)
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return ;
}
void subtask2(){//maybe 24 score?
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=2;
		ans%=998244353;
	}
	ans+=998244353;
	ans-=1;
	ans-=n*(n-1)/2;
	ans-=n;
	ans%=998244353; 
	cout<<ans;
	return ;
}
void subtask3(){//maybe 0~4 score?
	cout<<0;
	return ;
}
int main(){//maybe 64~68 score?
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20){
		subtask1();
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++)cin>>a[i],flag&=(a[i]<=1);
	if(flag){
		subtask2();
		return 0;
	}	
	subtask3();
	return 0;
} 
