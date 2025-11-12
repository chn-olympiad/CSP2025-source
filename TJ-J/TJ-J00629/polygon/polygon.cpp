#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const long long P=998244353;
int n,a[N],s[N*N];
long long ans[N],sum;
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	sort(a+1,a+1+n);
	s[a[1]]++;
	for (int i=3;i<=n;i++){
		ans[i]=ans[i-1];
		for (int j=2;j<i;j++){
			for (int k=sum;k>a[i]-a[j];k--)
				ans[i]=ans[i]+s[k]%P;
			s[a[j]]++;
			for (int k=sum;k>a[i]-a[j];k--)
				if (s[k] && k+a[j]<=sum)
					s[k+a[j]]++;
		}
		
	}
	cout<<1;
	return 0;
}
