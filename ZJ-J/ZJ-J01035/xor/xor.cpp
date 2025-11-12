#include<bits/stdc++.h>
using namespace std;
long long n,l,ans;
__int128 f[500010],a[500010],k,t;
string st;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>st;
	for(int j=0;j<st.size();j++) k=k*10+st[j]-48;
	for(int i=1;i<=n;i++){
		cin>>st;
		for(int j=0;j<st.size();j++) a[i]=a[i]*10+st[j]-48;
	}
	f[1]=a[1];
	for(int i=2;i<=n;i++) f[i]=a[i]^f[i-1];
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=l;j--){
			t=f[i];
			if(j!=0) t^=f[j];
			if(t==k){
				l=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}