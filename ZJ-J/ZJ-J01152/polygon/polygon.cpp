#include<bits/stdc++.h>
using namespace std;
int n,a[100005],choose[100005];long long ans=0;
int MAx(int a,int b){
	if(a>b)return a;
	if(a<=b)return b;
}
void check(){
	int sum=0,mx=-1,cnt=0;
	for(int i=0;i<n;i++){
		if(choose[i]==1){
			mx=MAx(mx,a[i]);
			cnt+=a[i];
			sum++;
		}
	}
	if(sum<3 or cnt<=2*mx)return;
	ans++;
	return;
}
void dfs(int idx,int chs){
	if(n-idx<3-chs)return;
	if(idx>=n){
		check();
		return;
	}
	choose[idx]=0;
	dfs(idx+1,chs);
	choose[idx]=1;
	dfs(idx+1,chs+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag==1){
		long long ann=1;
		for(int i=0;i<n;i++){
			ann*=2;			
			ann%=99824453;
		}
		ann-=n+1+n*(n-1)/2;
		if(ann<0)ann+=99824453;
		cout<<ann;
	}
	else{
		dfs(0,0);
		cout<<ans%99824453;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}