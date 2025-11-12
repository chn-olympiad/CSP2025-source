#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
vector<int> a(5020);
void jmax(){
	
}
void ef(){
	
}
void solve(int s){
	if(s==3){
		for(int i=1;i<=n;i++){
			
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
	a.resize(n+1);
	sort(a.begin(),a.end());
	/*for(int s=3;s<=n;s++){
		solve(s);
	}*/
	if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
		ans=1;
	}
	cout<<ans%998244353;
}
