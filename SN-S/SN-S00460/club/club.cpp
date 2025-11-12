#include<bits/stdc++.h>
using namespace std;
int const T=5,N=2e5+7;
int t,n,a[N],b[N],c[N];
long long ans,he3,he23,he1;
void dfs(int wei,long long anns,int num1,int num2,int num3,int li){
	if(num1>li) return ;
	if(num2>li) return ;
	if(num3>li) return ;
	if(wei==n+1){
		ans=max(ans,anns);
		return ;
	}
	int tmp=wei;
	dfs(wei+1,anns+a[tmp],num1+1,num2,num3,li);
	dfs(wei+1,anns+b[tmp],num1,num2+1,num3,li);
	dfs(wei+1,anns+c[tmp],num1,num2,num3+1,li);
	return ;
}
void dfs2(int wei,long long anns,int num1,int num2,int li){
	if(num1>li) return ;
	if(num2>li) return ;
	if(wei==n+1){
		ans=max(ans,anns);
		return ;
	}
	int tmp=wei;
	dfs2(wei+1,anns+a[tmp],num1+1,num2,li);
	dfs2(wei+1,anns+b[tmp],num1,num2+1,li);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			he3+=c[i];
			he23+=c[i]+b[i];
			he1+=a[i];
		}
		if(he3!=0&&he23!=0){
			int limi=n/2;
		dfs(0,0,0,0,0,limi);
		cout<<ans<<endl;
		continue;
		}
		if(he23==0){
			cout<<he1;
			continue;
		}
		if(he3==0){
			int limi=n/2;
		dfs2(0,0,0,0,limi);
		cout<<ans<<endl;
		continue;
		}
	}
	return 0;
}
