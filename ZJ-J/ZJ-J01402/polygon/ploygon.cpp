#include<iostream>
using namespace std;
bool flag[3005];
int height[3005],k,ans;
bool canbe(int sum1,int sum,int big){
	return sum>big*2&&sum1>=3;
}
void dfs(int sum1,int sum,int big,int to){
	if(canbe(sum1,sum,big)){
		ans++;
	}
	for(int i=to+1;i<k;i++){
		dfs(sum1+1,sum+height[i],max(big,height[i]),i);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>height[i];
	}
	dfs(0,0,0,-1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
