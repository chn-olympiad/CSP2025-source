#include<bits/stdc++.h>
using namespace std;
int a[5005],sum;
int n;
void dfs(int as,int k,int c){
	for(int i = k;i<=n;i++){
		if(as>a[i]&&c>=3){
			sum++;
			sum%=998244353;
		}
		dfs(as+a[i],i+1,c+1);
		dfs(as,i+1,c);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,1,0);
	cout<<sum-1;
	return 0;
} 
