#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int i=1;
int a[maxn];
int cnt=0;
bool cmp(int aa,int bb){
	return aa>bb;
}
int dfs(int n){
	if(n==0 or n<=i){
		//cout<<i<<" ";
		return a[n+1];
	}
	return a[n]+dfs(n-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int j=1;j<=n;j++){
		
		cin>>a[j];
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(j<=2){
				continue;
			}
			else {
				if(dfs(j)>a[i]){
					//cout<<j<<" ";
					cnt++;
				}
			}
		}
	} 
	cout<<cnt;
	return 0;
}
