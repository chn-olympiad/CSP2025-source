#include<bits/stdc++.h>
using namespace std;
int n;
int l[5001]={},ans=0;
int vis[5001];
int t[5001];
bool cmp(int a,int b){
	return a<b;
}
void dfs(int x,int f,int last){
	if(x==0){
		int lenmax=0,len=0;
		for(int i=1;i<f;i++){
			lenmax=max(lenmax,t[i]);
			len+=t[i];
		}
		if(len>2*lenmax){
			ans++;
			ans%=998244353;
		}
		//cout<<endl;
		return;
	}
	if(n-last<x){
		return;
	}
	for(int i=last+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			t[f]=l[i];
			dfs(x-1,f+1,i);
			t[f]=0;
			vis[i]=0;
		}
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
	sort(l+1,l+n+1,cmp);
	if(n==3){
		if(l[1]+l[2]+l[3]>max(max(l[1],l[2]),l[3])*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
