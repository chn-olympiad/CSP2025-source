#include <bits/stdc++.h>
using namespace std;
int n,k;
//样例都过了
//能不能给点分
//最努力的一集
//让孩子过吧
int a[500050];
int b[500050];
int dp[500050];
priority_queue <int> q[1500000]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[i] = a[i] ^ b[i-1];
		//cout<<b[i]<<' ';
	}
	//cout<<endl; 
	//截止到第i个数,最大数量
	for(int i = 1;i<=n;i++){
		dp[i] = dp[i-1];
		if(!q[b[i] ^ k].empty()){
			dp[i] = max(dp[i-1],dp[q[b[i] ^ k].top()]+1);
			//cout<<q[b[i] ^ k].top()<<endl;
		}else if(b[i] == k and !q[b[i] ^ k].empty()){
			dp[i] = max(dp[i-1],dp[q[b[i] ^ k].top()]+1);
		}else if(b[i] == k and dp[i] == 0){
			dp[i]++;
		}
		q[b[i]].push(i);
	}
//	for(int i = 1;i<=n;i++){
//		cout<<dp[i]<<' ';
//	}
	cout<<dp[n];
	return 0;
}
