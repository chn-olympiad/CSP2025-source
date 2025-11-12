#include<bits/stdc++.h>
using namespace std;
int n,k,num,ans=-0x7f7f7f7f;
int sum[20001][20001];
bool answer[15001][15001];
void dfs(int s,int deep){
	
	int flag=0;
	for(int i=s;i<=n;i++){
		if(answer[s][i]){
			dfs(i+1,deep+1);
			flag++;
		}
		dfs(i+1,deep);
	}
	if(!flag||s>n){
		if(deep>ans)ans=deep;
		return;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=i;j++){
			sum[j][i]=num^sum[j][i-1];
			if(sum[j][i]==k)answer[j][i]=answer[i][j]=1;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<answer[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		dfs(i,0);
	}
	cout<<ans;
}