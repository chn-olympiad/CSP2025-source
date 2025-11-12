#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,l[N],a[N],pos,cnt;
signed main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==k) l[++pos]=i,cnt++;
	}
	if(cnt==n||cnt==n-1){
		cout<<cnt;
		return 0;
	}
	l[pos+1]=n+1;
//	for(int p=0;p<=pos;p++) cout<<l[p]<<' '<<a[l[p]]<<endl; 
	for(int p=0;p<=pos;p++)
		for(int i=l[p]+1;i<l[p+1];i++){
			int ans=a[i];
			for(int j=i+1;j<l[p+1];j++){
				ans^=a[j];
//				cout<<ans<<' '<<i<<' '<<j<<'\n';
				if(ans==k){
					cnt++;
					i=j+1;
					break;
				}
			}
		}
	cout<<cnt;
	return 0;
}
/*
luogu:xxxyz求关喵 
（思路错了，T3挂分了qwq） 
*/
