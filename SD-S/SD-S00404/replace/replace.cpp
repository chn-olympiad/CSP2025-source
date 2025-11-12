#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;i++)
#define rf(i,j,k) for(int i=j;i>=k;i--)
#define mm(i) memset(i,0,sizeof i)
#define rm(i) memset(i,0x3f,sizeof i)
const int N=2e5+10;
const int mo=998244353;
const double pi=acos(-1.0);
using namespace std;
int n,m;
string s1[N],s2[N];
string x,y;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	f(i,1,n) cin>>s1[i]>>s2[i];
	f(i,1,m){
		cin>>x>>y;
		if(x.size()!=y.size()) cout<<"0\n";
		else{
			int bg=0,ed=0;
			for(int j=0;j<x.size();j++) if(x[j]!=y[j]){
				bg=j;
				break;
			}
			for(int j=x.size()-1;j>=0;j--) if(x[j]!=y[j]){
				ed=j;
				break;
			}
			x=x.substr(bg,ed-bg+1);
			y=y.substr(bg,ed-bg+1);
			int ans=0;
			f(j,1,n){
				if(s1[j].size()<x.size());
				else if(x==s1[j]&&y==s2[j]) ans++;
				else{
					int bg=0,ed=0;
					for(int k=0;k<s1[j].size();k++) if(s1[j][k]!=s2[j][k]){
						bg=k;
						break;
					}
					for(int k=s1[j].size()-1;k>=0;k--) if(s1[j][k]!=s2[j][k]){
						ed=k;
						break;
					}
					string s3=s1[j].substr(bg,ed-bg+1);
					string s4=s2[j].substr(bg,ed-bg+1);
					if(x==s3&&y==s4)ans++;			
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
