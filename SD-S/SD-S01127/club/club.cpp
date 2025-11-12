#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,Max;
struct node{
	int c1,c2,c3;
}a[200005];
void dfs(int i,int sum,int cnt1,int cnt2,int cnt3){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return ;
	if(i==n+1){
		Max=max(Max,sum);return ;
	}
	dfs(i+1,sum+a[i].c1,cnt1+1,cnt2,cnt3);
	dfs(i+1,sum+a[i].c2,cnt1,cnt2+1,cnt3);
	dfs(i+1,sum+a[i].c3,cnt1,cnt2,cnt3+1);
}
int T;
bool cmp(node x,node y){
	return x.c1>y.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;Max=0;
		int flag2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			if(a[i].c3!=0)flag2=1;
			if(a[i].c2!=0)flag2=1;
		}
		if(flag2!=0){
			dfs(1,0,0,0,0);
			cout<<Max<<'\n';
		}
		else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				Max+=a[i].c1;
			}
			cout<<Max<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
