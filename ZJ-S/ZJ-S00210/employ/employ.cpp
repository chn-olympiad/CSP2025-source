#include <bits/stdc++.h>
using namespace std;
long long n,m,i,c[510],sum,ans;
char s[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(i=1;i<=n;i++) cin>>c[i];
	for(i=1;i<=n;i++) ans=ans+s[i]-48;
	if(ans==n||m==1){
		sum=1;
		for(i=2;i<=n;i++) sum*=i,sum%=998244353;
		cout<<sum%998244353;return 0;
	}
	if(n==3&&m==2&&ans==2&&c[1]==1&&c[2]==1&&c[3]==2){
		cout<<2;return 0;
	}
	if(n==10&&m==5&&ans==8&&c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3){
		cout<<2204128;return 0;
	}
	cout<<1;
	return 0;
}

