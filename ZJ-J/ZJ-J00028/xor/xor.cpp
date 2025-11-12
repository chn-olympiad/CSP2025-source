#include<bits/stdc++.h>
#define int long long
using namespace std;
int jj=-1,ans,a[500005],flag=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++) if(a[i]==k) ans++;
		cout<<ans/*<<"hajiminanbeilvdou"*/;
		return 0;
	}
	int head=1,tail=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			head=tail=i+1;tail--;
			continue;
		}
		tail++;
		jj=a[tail];
		for(int j=tail-1;j>=head;j--){
			jj^=a[j];
			if(jj==k){
			//	cout<<j<<" "<<tail<<"\n";
				ans++;
				head=tail=i+1;tail--;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
