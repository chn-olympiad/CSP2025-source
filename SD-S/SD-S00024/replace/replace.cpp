#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[1000010],b[1000010];
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	while(next_permutation(a+1,a+n+1)){ 
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(b[i]>0&&s[i-1]=='1') ans++;
			if(b[i-1]=='0'){
				for(int j=i+1;j<=n;j++){
					b[j]--;
				}
			}
		}
		if(ans>=m) cnt++;
	}
	cout<<cnt%mod<<endl;
	return 0;
}
