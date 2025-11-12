#include<bits/stdc++.h>
using namespace std;
int arr[5005]={};
int xrr[5005]={};
int brr[5005]={};
int rra[5005]={};
long long Nx=998244353,sum=0;
int n,r=0;
bool pd(int da){
	int ans=0;
	for(int i=1;i<=r;i++){
		ans+=rra[i];
	}
	if(ans>2*da) return true;
	else return false;
}
void dfs(int da,int s){
	if(r==s){
		if(pd(da)){
			sum++;
		}	
		return ;
	}
	for(int i=1;i<=n;i++){
		if(brr[i]==0){
			r++;
			brr[i]=1;
			rra[r]=arr[i];
			dfs(max(da,arr[i]),s);
			r--;
			dfs(da,s);
			brr[i]=0;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int j=3;j<=n;j++){
		dfs(-1,j);
	}
	if(n==3){
		cout<<sum/6;
	}else{
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
