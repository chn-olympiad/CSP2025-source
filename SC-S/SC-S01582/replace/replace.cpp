#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,q;
string s[N][2],t,tt;
bool pre[N],lst[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>t>>tt;
		int len=t.size();
		if(t[0]==tt[0])pre[0]=true;
		else pre[0]=false;
		if(t[len-1]==tt[len-1])lst[len-1]=true;
		else lst[len-1]=false;
		lst[len]=true;
		for(int i=1;i<len;i++){
			if(t[i]==tt[i])pre[i]=pre[i-1];
			else pre[i]=false;
		}
		for(int i=len-2;i>=0;i--){
			if(t[i]==tt[i])lst[i]=lst[i+1];
			else lst[i]=false;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s[j][0][0]!=t[0]||s[j][1][0]!=tt[0])continue;
			if(s[j][0].size()>len)continue;
			if(lst[s[j][0].size()]==false)continue;
			bool flag=true;
			for(int k=1;k<s[j][0].size();k++){
				if(s[j][0][k]!=t[k]||s[j][1][k]!=tt[k]){
					flag=false;
					break;
				}
			}
			if(flag==true)ans++;
		}
		for(int i=1;i<len;i++){
			if(pre[i-1]==false)break;
			for(int j=1;j<=n;j++){
				if(s[j][0][0]!=t[i]||s[j][1][0]!=tt[i])continue;
				if(i+s[j][0].size()>=len)continue;
				if(lst[i+s[j][0].size()]==false)continue;
				bool flag=true;
				for(int k=1;k<s[j][0].size();k++){
					if(s[j][0][k]!=t[i+k]||s[j][1][k]!=tt[i+k]){
						flag=false;
						break;
					}
				}
				if(flag==true)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
