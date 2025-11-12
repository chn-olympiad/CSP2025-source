#include<bits/stdc++.h>
using namespace std;
string s[200005],t[200005],ss,tt,sss,ttt;
int n,q,ans,x[200005],y[200005],xx,yy,f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		x[i]=0;
		while(x[i]<s[i].size()&&s[i][x[i]]==t[i][x[i]])x[i]++;
		y[i]=1;
		while(y[i]<=s[i].size()&&s[i][s[i].size()-y[i]]==t[i][t[i].size()-y[i]])y[i]++;
	}
	while(q--){
		ans=0;
		cin>>ss>>tt;
		xx=0;
		while(ss[xx]==tt[xx])xx++;
		yy=1;
		while(ss[ss.size()-yy]==tt[tt.size()-yy])yy++;
		sss=ss.substr(xx,ss.size()-yy-xx+1);
		ttt=tt.substr(xx,tt.size()-yy-xx+1);
		for(int i=1;i<=n;i++){
			if(x[i]==s[i].size())continue;
			if(sss!=s[i].substr(x[i],s[i].size()-y[i]-x[i]+1)||ttt!=t[i].substr(x[i],t[i].size()-y[i]-x[i]+1))continue;
			if(xx-x[i]<0||y[i]-yy-1>=0)continue;
			f=1;
			for(int j=x[i]-1;j>=0;j--)if(ss[xx-x[i]+j]!=s[i][j])f=0;
			for(int j=s[i].size()-y[i]+1;j<s[i].size();j++)if(ss[ss.size()-yy+j-s[i].size()+y[i]]!=s[i][j])f=0;
			for(int j=x[i]-1;j>=0;j--)if(tt[xx-x[i]+j]!=t[i][j])f=0;
			for(int j=t[i].size()-y[i]+1;j<t[i].size();j++)if(tt[tt.size()-yy+j-t[i].size()+y[i]]!=t[i][j])f=0;
			ans+=f;
		}
		cout<<ans<<"\n";
	}
}
