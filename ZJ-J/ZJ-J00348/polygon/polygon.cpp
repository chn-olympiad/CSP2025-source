#include<bits/stdc++.h>
using namespace std;
long long chang[5005];
int cun[5005];
int k=0;
int n;
int qiuhe(int x,int y){
	int num=0;
	for(int i=x;i<=y;i++){
		num+=cun[i];
	}
	return num;
}
int maxs(int x,int y){
	int maxss=0;
	for(int i=x;i<=y;i++){
		if(cun[i]>=maxss){
			maxss=cun[i];
		}
	}
	return maxss;
}
void dfs(int num,int sum){
	if(sum>n){
		
		if(num>=4){
			if(qiuhe(1,num-1)>2*(maxs(1,num-1))){
				k++;
			}
			return;
		}
	}
	else{
		dfs(num,sum+1);
		cun[num]=chang[sum];
		dfs(num+1,sum+1);
		cun[num]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>chang[i];
	}
	dfs(1,1);
	cout<<k;
	return 0;
}
