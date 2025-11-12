#include<bits/stdc++.h>
using namespace std;
int n,sum,tmp,ka=0,temp,n3,n2;//tmp是所有最大值 
int ans[6000],k[6000];
void dfs(int t){
	if(t==0){
		for(int i=1;i<=n2;i++){
			temp+=k[i];//总和 
		}
		if(temp>=tmp*2){
			sum++;//发现成立的数 
			return;
		}
	}
	for(int i=ka+1;i<=n;i++){
		ka=i;
		k[t]=ans[i];
		n2++;
		dfs(t-1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ans[i];
	}
	//输入 
	for(int i=1;i<=n;i++){//最大数 
		if(ans[i]>tmp){
			tmp=ans[i];
		}
	}	
	if(n==3){
		int zong=ans[1]+ans[2]+ans[3];
		if(zong>tmp*2) sum++;	
	}
	//三角形 
	else{
		for(int i=3;i<=n;i++){	
			int n3=i;
			dfs(n3);
		} 
	}	
	sum=sum%998;
	sum=sum%353;
	sum=sum%224;		
	cout<<sum;
	return 0;
} 
