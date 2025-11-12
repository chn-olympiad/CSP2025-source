#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s11,s22,stot1,stot2,srs1[200010],srs2[200010],srs11[200010],srs22[200010];
bool check(string s1,string s2){
	ans=0;
	for(int i=1;i<=n;i++){
		s11=srs11[i];
		s22=srs22[i];
		for(int j=0;j<=s1.size()-s11.size();j++){
			stot1="";
			stot2="";
			for(int k=j;k<j+s11.size();k++){
				stot1+=s1[k];
				stot2+=s2[k];
			}
			if(stot1==s11&&stot2==s22){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>srs1[i]>>srs2[i];
	}
	for(int i=1;i<=n;i++){
		cin>>srs11[i]>>srs22[i];
	}
	for(int i=1;i<=m;i++){
		check(srs1[i],srs2[i]);
	}
	return 0;
}