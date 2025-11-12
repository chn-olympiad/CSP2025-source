#include<bits/stdc++.h>
using namespace std;
string tool[200011][2];
bool equ[200011];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>tool[i][0]>>tool[i][1],equ[i]=(tool[i][0]==tool[i][1]);
	for(int ii=1;ii<=q;ii++){
		int ans=0;
		string s,ss;
		cin>>s>>ss;
		int l=s.size()-1,r=0;
		for(int i=0;i<s.size();i++)
			if(s[i]!=ss[i])
				l=min(l,i),r=max(r,i);
		if(l>r){//×Ö·û´®ÏàÍ¬ 
			for(int i=1;i<=n;i++){
				if(equ[i]){
					long long x=s.find(tool[i][0]);
					if(x>=0&&x<s.size())
						ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				string pblm=s.substr(l,r-l+1),tgt=ss.substr(l,r-l+1);
				long long x=s.find(tool[i][0]),ps=tool[i][0].find(pblm),pss=tool[i][1].find(tgt);
				if(x>=0&&x<s.size()&&ps>=0&&ps<tool[i][0].size()&&pss>=0&&pss<tool[i][1].size()){
					for(int j=0;j<=l;j++){
						if(j+tool[i][0].size()>r&&s.substr(j,tool[i][0].size())==tool[i][0]&&ss.substr(j,tool[i][0].size())==tool[i][1]){
							ans++;
							break;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
