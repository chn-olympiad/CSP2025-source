#include<bits/stdc++.h>                         //^^^
using namespace std;
int a[500005],pre[500005];
bool vis[500005]
pair<int,int>p[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flag=true,num=0;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;}
	if(flag==true && k==0){
		for(int i=n-1;i>=1;i-=2){
			num+=i;}}
	cout<<num;
	fclose(stdin);fclose(stdout);
	return 0;}
