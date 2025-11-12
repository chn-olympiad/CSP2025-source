#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,q,l,r,ans;
string s[200005],ss[200005],sa,sb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
		l=0;
		r=0;
		if(s[i]==ss[i]){
			continue;
		}
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]!=ss[i][j]){
				l=j;
				break;
			}
		}
		for(int j=s[i].size()-1;j>=0;j--){
			if(s[i][j]!=ss[i][j]){
				r=j;
				break;
			}
		}
		s[i]=s[i].substr(l,r-l+1);
		ss[i]=ss[i].substr(l,r-l+1);
	}
	for(int i=1;i<=q;i++){
		cin>>sa>>sb;
		if(sa.size()!=sb.size()){
			cout<<"0\n";
			continue;
		}
		l=0;
		r=0;
		ans=0;
		for(int j=0;j<sa.size();j++){
			if(sa[j]!=sb[j]){
				l=j;
				break;
			}
		}
		for(int j=sa.size()-1;j>=0;j--){
			if(sa[j]!=sb[j]){
				r=j;
				break;
			}
		}
		sa=sa.substr(l,r-l+1);
		sb=sb.substr(l,r-l+1);
		for(int j=1;j<=n;j++){
			if(sa==s[j]&&sb==ss[j]){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
