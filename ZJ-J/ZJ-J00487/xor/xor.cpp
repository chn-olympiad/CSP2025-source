#include<bits/stdc++.h>
using namespace std;
const int cd=5e5+5;
int n,k,s[cd],a[cd];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt1+=(a[i]==1);
		cnt0+=(a[i]==0);
		s[i]=(s[i-1]^a[i]);
	}
	if(cnt1==n){//A
		cout<<n/2;	
	}
	else if(cnt1+cnt0==n){//B
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]&&a[i]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt0+cnt;
		}
		else if(k==1) cout<<cnt1;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
