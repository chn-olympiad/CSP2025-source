#include<bits/stdc++.h>
using namespace std;
bool s[1000];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,jj=0;cin>>n>>m;long long ans=0;
	{
		int m1=m;
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=0;i<n;i++)
			cin>>c[i];
		for(int i=0;i<n||m1>0;i++){
			if(s[i]=0){
				jj+1;continue;
			}
			else if(jj>c[i]&&s[i]==1){
				m1--;
			}
		}
		if(m1==0){
			ans++;ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
