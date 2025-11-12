#include<bits/stdc++.h>

using namespace std;
long long n,m,c[600],ans=1,cnt1,cnt2,w;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		if(c[i]==0) cnt2++;
		if(c[i]<=cnt1){
			cnt1++;
			if(cnt1==n-m){
				w=i;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
