#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=1e7+5;
int n,q,b[N][2],c[N][2],C[2*M];
bool flag=1;
string s[N][2],t[N][2];
void check(string s){
	int cnt=0;
	for(int i=1;i<(int)s.size();i++)
		if(s[i]!='a'&&s[i]!='b') flag=0;
		else if(s[i]=='b') cnt++;
	if(cnt!=1) flag=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i][0]=' '+s[i][0];s[i][1]=' '+s[i][1];
		check(s[i][0]);check(s[i][1]);
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		t[i][0]=' '+t[i][0];t[i][1]=' '+t[i][1];
		check(t[i][0]);check(t[i][1]);
	}
		for(int i=1;i<=n;i++) s[i][0].erase(0,1),s[i][1].erase(0,1);
		for(int i=1;i<=q;i++){
			t[i][0].erase(0,1);t[i][1].erase(0,1);
			int len1=0,len2=t[i][0].size()-1;
			for(int j=0;j<(int)t[i][0].size();j++){
				if(t[i][0][j]!=t[i][1][j]) break;
				len1++;
			}
			for(int j=(int)t[i][0].size()-1;j>=0;j--){
				if(t[i][0][j]!=t[i][1][j]) break;
				len2=j-1;
			}
			ll ans=0;
			for(int j=1;j<=n;j++){
				bitset<2005>b1,b2;
				int b=0;
				while(1){
					int p=t[i][0].find(s[j][0],b);
					if(~p){
						if(p<=len1&&p+s[j][0].size()-1>=len2) b1.set(p);
						b=p+1;
					}
					else break;
				}
				b=0;
				while(1){
					int p=t[i][1].find(s[j][1],b);
					if(~p){
						if(p<=len1&&p+s[j][0].size()-1>=len2) b2.set(p);
						b=p+1;
					}
					else break;
				}
				ans+=(b1&b2).count();
			}
			cout<<ans<<'\n';
		}
	return 0;
}
