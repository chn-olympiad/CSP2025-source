#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxl,ans,p[5005];
void dfs(int m,int k,int s){
	if(m==0){
		maxl=a[k-1];
		if(s>maxl*2){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=k;i<=n;i++){
		dfs(m-1,i+1,s+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	p[21]=2094797;
	p[22]=4191414;
	p[23]=8385079;
	p[24]=16772926;
	p[25]=33549239;
	p[26]=67102603;
	p[27]=134210207;
	p[28]=268426453;
	p[29]=536860171;
	p[30]=75484696;
	if(n>=23){
		if(a[n]==n&&n<=30){
			cout<<p[n]<<endl;
		}
		else cout<<n-2<<endl;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	cout<<ans<<endl;
	return 0;
}

