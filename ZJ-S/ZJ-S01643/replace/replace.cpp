#include<bits/stdc++.h>
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
#define ff(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
using namespace std;
const int N=2e5+10;
int n,q;
int flagB;
string s1[N],s2[N];
string t1,t2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ff("replace");
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int len1=s1[i].size(),len2=s2[i].size();
		for(int j=0;j<len1;j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b')flagB=1;
		}
		for(int j=0;j<len2;j++){
			if(s2[i][j]!='a'&&s2[i][j]!='b')flagB=1;
		}
	}
	if(!flagB){
		while(q--){
			int ans=0;
			cin>>t1>>t2;
			int len=t1.size();
			int pos1=-1,pos2=-1;
			for(int i=0;i<len;i++){
				if(t1[i]=='b')pos1=i;
				if(t2[i]=='b')pos2=i;
			}
			int del=pos2-pos1;
//			cout<<del<<"\n";
			int p1=-1,p2=-1;
			for(int i=1;i<=n;i++){
				int ll=s1[i].size();
				p1=s1[i].find("b");
				p2=s2[i].find("b");
//				for(int j=0;j<ll;j++){
//					if(s1[i][j]=='b')p1=j;
//					if(s2[i][j]=='b')p2=j;
//				}
				if(p2-p1==del){
					if(ll-p1<=len-pos1&&p1<=pos1)ans++;
				}
			}
//			cout<<ans<<"\n";
		}
	}
	else {
		while(q--){
			int ans=0;
			cin>>t1>>t2;
			int len=t1.size();
			string core1="",core2="";
			int st,ed;
			for(int i=0;i<len;i++){
				if(t1[i]!=t2[i]){
					st=i;
					break;
				}
			}
			for(int i=len-1;i>=0;i--){
				if(t1[i]!=t2[i]){
					ed=i;
					break;
				}
			}
			for(int i=st;i<=ed;i++){
				core1+=t1[i];
				core2+=t2[i];
			}
			for(int i=1;i<=n;i++){
				if(t1.find(s1[i])!=-1&&s1[i].find(core1)!=-1&&t2.find(s2[i])!=-1&&s2[i].find(core2)!=-1){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}


