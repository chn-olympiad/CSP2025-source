#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[100001][3];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0,o=n/2;
		int u[100001]={};
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			u[i]=a[i][1];
		}
		sort(u+1,u+n+1,cmp);
		for(int i=1;i<=o;i++){
			ans+=u[i];
		}
		cout<<ans;
	}
	return 0;
}