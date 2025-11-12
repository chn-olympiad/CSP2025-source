#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int n,T;
int pre[N][3];
int suf[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'){
				pre[i][1]=j;
				suf[i][1]=s1.size()-1-j;
			}
			if(s2[j]=='b'){
				pre[i][2]=j;
				suf[i][2]=s1.size()-1-j;
			}
		}
	}
	while(T--){
		string t1,t2;
		cin>>t1>>t2;
		int p1,s1,p2,s2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
		}
		else{
			for(int i=1;i<=t1.size();i++){
				if(t1[i]=='b'){
					p1=i;
					s1=t1.size()-1-i;
				}
				if(t2[i]=='b'){
					p2=i;
					s2=t1.size()-1-i;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(p1>=pre[i][1]&&s1>=suf[i][1]&&p1-pre[i][1]+pre[i][2]==p2&&s1-suf[i][1]+suf[i][2]==s2){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
