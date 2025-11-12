#include<bits/stdc++.h>
using namespace std;
int n,sum = 0,bo[5010] = {},a[5010] = {};
void work(){
	if(sum > 998)sum %= 998;
	if(sum > 244)sum %= 244;
	if(sum > 353)sum %= 353;
}
void dfs(int dfs_st,int deep,int now_sum,int up,int mx){
	if(deep > up){
		if(now_sum > mx * 2){
			sum++;
		}
		work();
		return;
	}
	for(int i = dfs_st;i <= n ;i++){
		dfs(i+1,deep + 1,now_sum + a[i],up,max(mx,a[i]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i  =1;i <=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 3;i <= n;i++){
		dfs(1,1,0,i,1);
	}
	printf("%d",sum,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
