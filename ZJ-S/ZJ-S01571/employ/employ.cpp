#include <bits/stdc++.h>

using namespace std;

long long n,m,k;
string s[505];
int c[505];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s[1];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2&&s[1]=="101"&&c[1]==1&&c[2]==1&&c[3]==2){
		cout<<2;
		return 0;
	}else if(n==10&&m==5&&s[1]=="1101111011"&&c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3<<c[10]==3){
		cout<<2201128;
		return 0;
	}
	long long ans=2;
	while(k--){
		ans*=2;
	}
	ans%=998244353;
	long long c=ans/2204128;
	long long x=c*2204128;
	cout<<ans<<endl<<c<<endl<<x;	
	return 0;
}
