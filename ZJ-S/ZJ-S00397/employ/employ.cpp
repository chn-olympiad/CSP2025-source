#include<bits/stdc++.h>
using namespace std;
long long n,m,t[100005],a[100005],id[100005],c,y,ans;
char s[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<strlen(s);i++){
		t[i+1]=s[i]-48;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		id[i]=i;
	}
	do{
		c=y=0;
		for(int j=1;j<=n;j++){
			long long i=id[j];
			if(c>=a[i])c++;
			else {
				if(t[j]==0)c++;
				else y++;
			}
		}
		if(y>=m)ans=(ans+1)%998244353;
	}while(next_permutation(id+1,id+n+1));
	cout<<ans%998244353;
	return 0;
}
