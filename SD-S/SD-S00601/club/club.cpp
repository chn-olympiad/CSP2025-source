#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct node{
	int num1,num2,num3;
}a[555];
void dfs(int x,int num1,int num2,int num3,long long sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(num1<(n/2))dfs(x+1,num1+1,num2,num3,0ll+sum+a[x].num1);
	if(num2<(n/2))dfs(x+1,num1,num2+1,num3,0ll+sum+a[x].num2);
	if(num3<(n/2))dfs(x+1,num1,num2,num3+1,0ll+sum+a[x].num3);
}
bool cmp(node tmp1,node tmp2){
	return tmp1.num1>tmp2.num1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		int flag=1;
		for(int i =1;i<=n;i++){
			cin>>a[i].num1>>a[i].num2>>a[i].num3;
			if(a[i].num2)flag=0;
		}
		if(flag){
			sort(a+1,a+1+n,cmp);
			for(int i =1;i<=n/2;i++)ans+=a[i].num1;
			cout<<ans<<"\n";
			continue;
		}
		else{
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//bao li
