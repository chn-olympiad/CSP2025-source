#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5002],ans;
void search(int k,long long sum){
	for(int i=k;i<n;i++){
		if(sum>a[i])ans=(ans+1)%mod;
		search(i+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			search(j+1,a[i]+a[j]);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
