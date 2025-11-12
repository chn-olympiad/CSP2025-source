#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s1,s2,s3[100010],s4[100010],st1,st2,st3,st4;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				s3[i]+=s1[j];
				s4[i]+=s2[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>st1>>st2;
		for(int j=0;j<st1.size();j++){
			if(st1[j]!=st2[j]){
				st3+=st1[j];
				st4+=st2[j];
			}
		}
		for(int k=1;k<=n;k++){
			if(st3==s3[k]&&st4==s4[k])ans++;
		}
		cout<<ans<<'\n';
		st3="";
		st4="";
		ans=0;
	}
	return 0;
}
