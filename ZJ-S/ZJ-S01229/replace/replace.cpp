#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,T,i,j,ans;
string s[200010][3],s1,s2,a,b;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>T;
	for (i=1;i<=m;i++) cin>>s[i][1]>>s[i][2];
	while (T--){
		cin>>s1>>s2;
		n=s1.size();ans=0;
		if (n!=s2.size()){cout<<"0\n";continue;}
		for (i=0;i<n;i++)
			for (j=1;i+j-1<n;j++){
				a=s1.substr(i,j);
				for (k=1;k<=m;k++)
					if (s[k][1]==a){
						b=s1.substr(0,i)+s[k][2]+s1.substr(i+j,n-i-j+1);
						if (b==s2) ans++;
					}
			}
		cout<<ans<<"\n";
	}
	return 0;
}
