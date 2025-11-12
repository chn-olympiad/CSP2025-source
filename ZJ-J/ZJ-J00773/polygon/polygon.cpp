#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[250005],s[250005],f[250005],maxs;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxs+=a[i];
	}
	sort(a+1,a+n+1);
	maxs-=a[n];
	if(a[n]==1){
		int k=1;
		s[1] = 2;
		s[2] = 1;
		for(int i=3;i<=n;i++){
			ans+=k;
			ans%=mod;
			for(int j=i;j>=2;j--){
				s[j]+=s[j-1];
				s[j]%=mod;
				k+=s[j-1];
				k%=mod;
			}
			s[1]++;
		}
		cout<<ans;
		return 0;
	}
	f[a[1]]++;
	f[a[2]]++;
	s[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=maxs;j++){
			ans+=s[j];
			ans%=mod;
		}
		for(int j=maxs-a[i];j>=1;j--){
			if(s[j]||f[j]){
				s[j+a[i]]+=s[j]+f[j];
				s[j+a[i]]%=mod;
			}
		}
		f[a[i]]++;
		f[a[i]]%=mod;
	}
	cout<<ans;
	return 0;
}
