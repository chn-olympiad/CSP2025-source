#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5;
ll ans;
int l[N],n;
bool cmp(int x,int y){
	return x>y;
}
int c[N]={0};
void dfs(int all_steps,int now_step){
	if(now_step==all_steps){
		int mx=l[c[1]];
		int sum=0;
		for(int i=2;i<=all_steps;i++){
			sum+=l[c[i]];
		}
		if(mx<sum){
			ans++;
		}
		return;
	}
	for(int i=c[now_step]+1;i<=n-(all_steps-now_step)+1;i++){
		c[now_step+1]=i;
		dfs(all_steps,now_step+1);
		c[now_step+1]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+1+n,cmp); 
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(l[1]>l[2]+l[3]){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		for(int i=3;i<=n;i++){
			dfs(i,0);
		}
		cout<<ans;
	}
	return 0;
}
