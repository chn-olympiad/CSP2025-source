#include<bits/stdc++.h>
using namespace std;
int t,n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int a[100005]={0};
		long long ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			int w,e;
			cin>>a[j]>>w>>e;
		}
		sort(a+1,a+n+1,cmp);
		for(int j=1;j<=n/2;j++){
			ans+=a[j];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

