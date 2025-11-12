#include<bits/stdc++.h>
using namespace std;
int arr[5005]={};
int brr[5005]={};
int n,r=0,ans=0,z,q=0,big=-1;
void dfs(int x,int step){
	if(step==z){
		if(q>big*2) ans++;
		return ;
	}
	int w=big;
	r++;
	brr[r]=arr[x];
	q+=arr[x];
	big=max(big,arr[x]);
	dfs(x+1,step+1,z);
	brr[r]=0;
	r--;
	big=w;
	dfs(x+1,step,z);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int z=3;z<=n;z++){
		for(int i=1;i<=n;i++){
			r++;
			brr[r]=arr[i];
			q+=arr[i];
			dfs(i,1,z);
			brr[r]=0;
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
