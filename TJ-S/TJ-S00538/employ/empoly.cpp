#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000];
string s;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","r",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int x=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				x=i;
				break;
			}
		}
		int cnt=n;
		for(int i=1;i<=n;i++){
			if(a[i]>x) cnt--;
		}
		cout<<cnt%998244353;
		return 0;
	}
	if(m==n){
		long long cnt=1;
		for(int i=1;i<=n;i++){
			cnt*=i;
			cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
