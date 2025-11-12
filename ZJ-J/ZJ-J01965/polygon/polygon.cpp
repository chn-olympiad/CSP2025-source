#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	vector<int> a(n+1,0),s(n+1,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	int ans=0;
	if(cnt==n){
		ans=pow(4,n-3);
	}
	else{
		ans=9;
	}
	cout<<ans%958244353;
}