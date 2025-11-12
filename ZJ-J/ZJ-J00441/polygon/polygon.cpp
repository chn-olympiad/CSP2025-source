#include<bits/stdc++.h>
using namespace std;
int n,num=0,da=-10000;
long long ans=0;
int a[5020],b[5020];
bool vis[5020];
void dfs(int m,int step,int j){
	if(step>m){
		num=0;
		for(int i=1;i<=step-1;i++){
			num+=b[i];}
		if(num>b[step-1]*2){
			//cout<<num<<' '<<b[step-1]*2<<endl;
			ans=(ans+1)%998244353;}
		return;}
	for(int i=j;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			b[step]=a[i];
			dfs(m,step+1,i);
			vis[i]=false;}}}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>da) da=a[i];}
	if(da==1){
		cout<<0;
		return 0;}
	sort(a+1,a+n+1);
	//for(int i=3;i<=n;i++) dfs(i,1);
	for(int i=1;i<=n;i++) dfs(i,1,1);
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;}