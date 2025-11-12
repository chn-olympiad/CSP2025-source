#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2e5+5,base=197;
int n,q,sum[N],ans;
string s[N][2],t[N][2];
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++){
		int l=-1,r=-1;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!=t[i][1][j]){
				l=j;
				break;
			}
		}
		for(int j=t[i][0].size()-1;j>=0;j--){
			if(t[i][0][j]!=t[i][1][j]){
				r=j;
				break;
			}
		}
		r++;
		string x=t[i][0].substr(0,l),y=t[i][0].substr(l,r-l),z=t[i][0].substr(r,t[i][0].size()-r);
		for(int j=1;j<=n;j++){
			if(s[j][0]==y&&x+s[j][1]+z==t[i][1]){
				ans++;
				cout<<"string"<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
