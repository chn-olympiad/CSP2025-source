#include<bits/stdc++.h>
using namespace std;
int n,a[100010][5],f[3][1010][1010],res;
bool checka(){
	for(int i=1;i<=n;i++)if(a[i][2]!=0||a[i][3]!=0)return false;
	return true;
}
bool checkb(){
	for(int i=1;i<=n;i++)if(a[i][3]!=0)return false;
	return true;
}
void solve(){
	res=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)cin>>a[i][j];
	if(checka()){
		int b[100010]={0};
		for(int i=1;i<=n;i++)b[i]=a[i][1];
		sort(b+1,b+1+n,greater<int>());
		for(int i=1;i<=n/2;i++)res+=b[i];
		return cout<<res<<'\n',void();
	}
	if(checkb()){
		pair<int,int> b[100010]={make_pair(0,0)};
		for(int i=1;i<=n;i++)b[i].first=a[i][1],b[i].second=a[i][2];
		sort(b+1,b+1+n,greater<pair<int,int> >());
		for(int i=1;i<=n;i++)res+=b[i].first;
		for(int i=1;i<=n;i++)b[i].first=b[i].second-b[i].first;
		sort(b+1,b+1+n,greater<pair<int,int> >());
		for(int i=1;i<=n/2;i++)res+=b[i].first;
		return cout<<res<<'\n',void();
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(n/2,i);j++){
			for(int k=max(i-n/2-j,0);k<=min(n/2,i)&&j+k<=i&&(i-k-j)<=n/2;k++){
				if(j+k<i)f[i&1][j][k]=max(f[i&1][j][k],f[(i-1)&1][j][k]+a[i][3]);
				if(j)f[i&1][j][k]=max(f[i&1][j][k],f[(i-1)&1][j-1][k]+a[i][1]);
				if(k)f[i&1][j][k]=max(f[i&1][j][k],f[(i-1)&1][j][k-1]+a[i][2]);
			}
		}
	}
	for(int j=0;j<=n/2;j++){
		for(int k=max(n-n/2-j,0);k<=n/2&&j+k<=n&&(n-k-j)<=n/2;k++){
			res=max(res,f[n&1][j][k]);
		}
	}
	cout<<res<<'\n';
	memset(f,0,sizeof f);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _;cin>>_;
	while(_--)solve();
	return 0;
}

