#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	int a[5050]={0};
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) a[i]+=a[i-1];
	for(int i=3;i<=n;++i){
		for(int j=i;j<=n;++j){
			if((a[j]-a[j-i])>(a[j]-a[j-1])*2) ans++;
		}
	}
	cout<<ans;
	return 0;
}
