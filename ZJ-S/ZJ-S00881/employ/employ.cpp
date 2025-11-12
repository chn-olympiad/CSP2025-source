#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],ans,l=0;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]=='1'){
			l++;
		}
	}
	sort(c+1,c+1+n);
	if(l==n){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(l<m){
		cout<<"0\n";
		return 0;
	}
	int y=0;ans=1;
	for(int i=1;i<=m;i++){
		int x=m-i+1;
		if(s[i-1]=='0'){
			y++;
			for(int j=1;j<=n;j++){
				if(c[i]<=y){
					x--;
				}
			}
		}
		if(x<=0)x=1;
		ans=ans*x%mod;
	}
	for(int i=m+1;i<=n;i++){
		int x=n-i+1;
		
		ans=ans*x%mod;
	}
	cout<<ans;
	return 0;
}
