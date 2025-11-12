#include<bits/stdc++.h>
#define int long long
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,q;
const int N=2e5+5;
string s[N][2];
signed main(){
	IOS();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		int m=s[i][0].size();
		int l,r;
		for(l=0;l<m;++l)if(s[i][0][l]!=s[i][1][l])break;
		for(r=m-1;r>0;--r)if(s[i][0][r]!=s[i][1][r])break;
		if(l==0&&r==m-1)continue;
		string check1="",check2="";
		for(int j=l;j<=r;++j){
			check1=check1+s[i][0][j];
			check2=check2+s[i][1][j];
		}
		s[i][0]=check1,s[i][1]=check2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int m=t1.size();
		int l,r;
		for(l=0;l<m;++l)if(t1[l]!=t2[l])break;
		for(r=m-1;r>=0;--r)if(t1[r]!=t2[r])break;
		string check1="",check2="";
		for(int i=l;i<=r;++i){
			check1=check1+t1[i];
			check2=check2+t2[i];
		}
		int ans=0;
		for(int i=1;i<=n;++i)if(check1==s[i][0]&&check2==s[i][1])ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
