#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000+10],ans;
void dfs(int now,int to,int m,int cnt){
	if(now>n){
		if(to>2*m&&cnt>=3) ans++;
		return ;
	}
	dfs(now+1,to+a[now],max(m,a[now]),cnt+1);
	dfs(now+1,to,m,cnt);
}
int jx(int x,int y){
	int num=1;
	for(int i=x;i>=x-y+1;i--){
		num*=i;
	}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		for(int i=3;i<=n;i++){
			ans+=jx(n,i)/jx(i,i);
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}