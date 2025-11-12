#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],nw,ans,b[500005],s[500005],cnt;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k<=1||n>=3000||n<=100){
		for(int i=1;i<=n;i++){
			if((nw^a[i])==k){
				ans++;
				nw=0;
			}else if(a[i]==k){
				nw=0;
				ans++;
			}else{
				nw^=a[i];
			}
		}
		cout<<ans;	
	}else{
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]^a[i];
			if(a[i]==k)b[++cnt]=i;
		}
		b[cnt+1]=n+1;
		for(int i=1;i<=cnt;i++){
			for(int j=b[i]+1;j<b[i+1];j++){
				for(int l=j+1;l<b[i+1];l++){
					if(s[l]^s[j-1]==k){
						ans+=1;
						j=l+1;
						break;
					}
				}
			}
		}
		cout<<ans+cnt;	
	}
	return 0;
}

