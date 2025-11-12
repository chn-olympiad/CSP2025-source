//SN-J00016
//感觉像DP,但我不会(懒得想了),遂不可以,总司令! (假完了 
#include<bits/stdc++.h>
using namespace std;
using ll= long long;
ll n,a[1000005],maxx,ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	cout<<"RP++";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			maxx=-1,sum=0;
			for(int k=j;k<=i+j;k++){
				sum+=a[k];
				maxx=max(maxx,a[k]);
			}
			//cout<<sum<<" "<<maxx<<"\n";
			if(sum>2*maxx)ans++;
		}
	}
	cout<<ans;
	return 0;
}
