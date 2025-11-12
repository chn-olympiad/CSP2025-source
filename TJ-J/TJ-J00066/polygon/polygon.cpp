#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int n;
int a[600005]={0},s[600005]={0},v[600005]={0},c[600005]={0};
int ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]++;
	}
	sort(a+1,a+1+n);
	int l=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(i>=3){
			c[l]+=i;
			c[s[i]]+=-1*i;
			l=s[i];
		}
	}
	for(int i=1;i<=n;i++) c[i]=c[i-1]+c[i];
	for(int i=3;i<=n;i++){
		if(c[2*a[i]]==0) continue;
		if(a[c[a[i]*2]]>a[i]){
			continue;
		}
		ans+=(n-c[2*a[i]]+1);
		ans%=M;
	}
	cout<<ans+1<<endl;
	return 0;
}

