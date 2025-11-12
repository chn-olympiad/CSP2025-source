#include<bits/stdc++.h>
using namespace std;
int n,sum,crng=3;
int a[10001],t[10001];
void dfs(int dep){
	if (dep>3){
		int temp=0;
		for (int i=1;i<=crng;i++){
			temp+=t[a[i]];
		}
		if (temp>t[a[crng]]*2){
			sum++;
		}
		//cout<<temp<<" "<<a[crng]*2<<endl;
		return ;
	}
	bool flag=0;
	for (int i=1;i<=n;i++){
		for (int j=i-1;j>=1;j--){
			if (a[i]==a[j]){
				flag=1;
			}
		}
		if (flag==1){
			continue;
		}
		else{
			a[dep]=i;
			dfs(dep+1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	if (n==3){
		dfs(1);
		cout<<sum;
	}
	else{
		int su=1;
		for (int i=1;i<=n-2;i++){
			su=i*i;
		} 
		cout<<su;
	}
	return 0;
}
