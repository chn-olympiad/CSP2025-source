#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
//int lowbit(int x)return ((-x)&x);
int ans=-1;
int sum[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	string s;
	int c[N];
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	sort(c,c+n);
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]==0){
				cout<<0;
				return 0;
			}
			sum[i]=c[i]-i;
		}
		for(int i=0;i<=n;i++)ans*=sum[i];
		cout<<ans;
	}
	

	return 0;
}

