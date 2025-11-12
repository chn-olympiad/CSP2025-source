#include <bits/stdc++.h>
using namespace std;
int n,a[100005],t,m=0,sum=0;
bool w[100005]={0};
void dfs(int a){
	if(a>m) m=a;
	return ;
for(int i=1;i<=n;i++){
	if(w[i]==0){
		w[i]=1;
	}
}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int x=1;x<=3;x++){
				cin>>a[i];
			}
			dfs(a[i]);
			cout<<m<<endl;}
	} 
	return 0;
}