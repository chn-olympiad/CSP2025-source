#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,m,c[600],a[600],sa[600],ans=1,sum=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	//for(int i=0;i<n;i++)a[i+1]=a[i]+1^(s[i]-'0');
	for(int i=1;i<=n;i++){
		cin>>c[i];if(c[i]==0)sum++;
		//sa[i]=upper_bound(a+1,a+1+n,c[i])-a-1;
	}
	sort(sa+1,sa+1+n,cmp);
	for(int i=n-sum,j=1;j<=m;i--,j++){
		ans=ans*i;
	}
	for(int i=1;i<=m;i++){
		ans/=i;
	}
	for(int i=n,j=1;j<=m;i--,j++)ans=ans*i;
	cout<<ans%998244353;
}
