#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a[3*n+1];
		for(int i=1;i<=3*n;i++){
			cin>>a[i];
		}
		sort(a,a+3*n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans;
	}
	
	
	
	return 0;
}
