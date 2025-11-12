//SN-J01140 西安高新第二初级中学 韦博彦 
#include<bits/stdc++.h>
using namespace std;
int a[5005],n,sum;
void dfs(int cnt,int maxx,int root){
	if(root==n){
		sum++;
		return ;
	}
	if(cnt+a[root]>maxx*2){
		if(a[root]>maxx) maxx=a[root];
		dfs(cnt+a[root],maxx,root+1);
	}
	dfs(cnt,maxx,root+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,-1,1);
	cout<<sum;
	return 0;
}
//超时多少啊 ？ 
 
