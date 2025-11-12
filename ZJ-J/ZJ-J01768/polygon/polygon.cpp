#include<bits/stdc++.h>
using namespace std;
int n,k=1,a[50004],flag[50003];
long long ansss;
struct node{
	int num,id;
}ans[1003];
void dfs(int now){
	if(now>=3){
		k++;
		int maxx=-100,sum=0;
		for(int i=0;i<now;i++){
			maxx=max(maxx,ans[i].num);
			sum+=ans[i].num;
		}
		if(sum>maxx*2){
			ansss++;
			ansss%=998244353;
		}
	}
	for(int i=now+1;i<=n;i++){
		if(flag[i]==0&&i>ans[now-1].id){
			ans[now].num=a[i];
			ans[now].id=i;
			now++;
			flag[i]=1;
			dfs(now);
			flag[i]=0;
			now--;
			ans[now].id=0;
			ans[now].num=0;
		}
		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0);
	cout<<ansss%998244353;
	return 0;
}
