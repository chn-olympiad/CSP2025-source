#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[200010][3],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len=t1.length();
		if(t1.length()!=t2.length()){
			cout<<"0\n";
			continue;
		}
		int ans=0,r=len-1,l=0;
		while(l<=r&&t1[l]==t2[l])l++;
		while(r>=0&&t1[r]==t2[r]){
			r--;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(len-(int)s[i][1].length(),l);j++){
				if(j+s[i][1].length()<=r)continue;
				bool b=1;
				for(int x=0;x<s[i][1].length();x++){
				 	if(s[i][1][x]!=t1[x+j]||s[i][2][x]!=t2[x+j]){
				 		b=0;
				 		break;
					}
				}
				if(b)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

