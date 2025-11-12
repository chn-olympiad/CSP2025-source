#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y,ch[10000005],wei[10000005];
string a,b,c[1005],d[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n*m<=1e6){
		for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
		for(int i=1;i<=m;i++){
			int ans=0;
			cin>>a>>b;
			string s=a;
			for(int j=1;j<=n;j++){
				for(int k=0;k+c[j].size()<=s.size();k++){
					s=a;
					if(s[k]==c[j][0]){
						int tag=1,kk=0;
						while(kk<c[j].size()){
							if(s[kk+k]!=c[j][kk]){
								tag=0;break;
							}
							++kk;
						}
						if(tag){
							kk=0;
							while(kk<c[j].size()){
								s[k+kk]=d[j][kk];kk++;
							}
						}
					}
					bool fla=1;
					for(int l=0;l<s.size();l++){
						if(s[l]!=b[l]){
							fla=0;
							break;
						}
					}
					if(fla)ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(int j=1;j<=n;j++){
		cin>>a>>b;
		for(int i=0;i<a.size();i++)if(a[i]=='b'){x=i;break;}
		for(int i=0;i<b.size();i++)if(b[i]=='b'){y=i;break;}
		ch[x-y+(int)5e6]++;
		wei[x-y+(int)5e6]=a.size()-x;
	}
	for(int j=1;j<=m;j++){
		cin>>a>>b;
		for(int i=0;i<a.size();i++)if(a[i]=='b'){x=i;break;}
		for(int i=0;i<b.size();i++)if(b[i]=='b'){y=i;break;}
		if(wei[x-y+(int)5e6]>a.size()-x)cout<<ch[x-y+(int)5e6]-1<<"\n";
		else cout<<ch[x-y+(int)5e6]<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
 
*/
