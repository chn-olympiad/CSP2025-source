#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q;
map<pair<string,string>,bool>f;
string s[2000200][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&Q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		f[{s1,s2}]=true;
	}
	while(Q--){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				l=i;
				break;
			}
		}for(int i=s1.size()-1;i>=0;i--)
			if(s1[i]!=s2[i]){
				r=i;
				break;
			}
		string s3="",s4="";
		for(int i=l;i<=r;i++){
			s3+=s1[i];
			s4+=s2[i];
		}s[l][0]="";
		s[l][1]="";
		s[r][0]="";
		s[r][1]="";
		for(int i=l-1;i>=0;i--){
			s[i][0]=s1[i]+s[i+1][0];
			s[i][1]=s2[i]+s[i+1][1];
		}for(int i=r+1;i<s1.size();i++){
			s[i][0]=s[i-1][0]+s1[i];
			s[i][1]=s[i-1][1]+s2[i];
		}
		int ans=0;
		for(int i=l;i>=0;i--){
			for(int j=r;j<s1.size();j++){
				if(f[{s[i][0]+s3+s[j][0],s[i][1]+s4+s[j][1]}]){
					ans++;
				}
//				cout<<i<<" "<<j<<" "<<s[i][0]+s3+s[j][0]<<' '<<s[i][1]+s4+s[j][1]<<endl;
			}
		}printf("%lld\n",ans);
	}
	return 0;
}