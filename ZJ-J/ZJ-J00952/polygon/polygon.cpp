#include<bits/stdc++.h>
using namespace std;
long long n,a[10100],o[101010],ans;
void dfs(int step,int last,int chu){
	if(chu+1==step){
		long long maxx=0,sum=0;
		for(int i=1;i<=chu;i++){
			maxx=max(maxx,o[i]);
			sum+=o[i];
			//cout<<o[i]<<" ";
		}
		//cout<<endl<<sum<<" "<<maxx<<endl;
		if(sum>maxx*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		o[step]=a[i];
		dfs(step+1,i,chu);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==1){
		for(int i=3;i<=n;i++){
			dfs(1,0,i); 
		}	 
	}
	cout<<ans;
	return 0;
}
