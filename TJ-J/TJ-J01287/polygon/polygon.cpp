#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000];
bool b[10000];
long long ggg=0;
void dfs(int k,int maxn,int zh){
	maxn=max(a[k],maxn);
	if(zh>maxn*2){
		ggg=(ggg%998244353+1)%998244353;
	}
	
	for(int i=n;i>=k+1;i--){
		if(b[i]==0){
			b[i]=1;
			dfs(i,maxn,zh+a[i]);
			b[i]=0;
		}
		
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		dfs(i,a[i],a[i]);
		
	}
	
	cout<<ggg%998244353;
	
	
	
	//cout<<n;//#Shang4Shan3Ruo6Shui4
	return 0;
}
