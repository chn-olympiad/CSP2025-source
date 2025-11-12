#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],s3[200005];
int s4[200005],ff=1;
int dp[500005];
bool isprime(string s){
	int xx=1,xxx=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='b') xxx++,xx--;
		else if(s[i]!='a') xx--;
	}
	return (xxx==1&&xx==0);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		string t;
		int f=1;
		if(!isprime(s1[i])||!isprime(s2[i])) ff=0;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]!=s2[i][j]){
				if(f==1||t.size()==0){
					if(f==1) s4[i]=j;
					s3[i]+=s2[i][j];
					f=0;
					t="";
				}
				else s3[i]+=t,t="";
			}
			else t+=s1[i][j];
		}
	}
	if(ff==1){
		for(int i=1;i<=n;i++){
			int xx,yy;
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b') xx=j;
			}
			for(int j=0;j<s2[i].size();j++){
				if(s2[i][j]=='b') yy=j;
			}
			s4[i]=xx-yy;
			dp[xx-yy+500000]++;
		}
		while(q--){
			string s,t;
			cin>>s>>t;
			int xx,yy;
			for(int j=0;j<s.size();j++){
				if(s[j]=='b') xx=j;
			}
			for(int j=0;j<t.size();j++){
				if(t[j]=='b') yy=j;
			}
			cout<<dp[xx-yy+500000]<<'\n';
		}
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		string k,l;
		int f=1,z,sum=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=t[i]){
				if(f==1||k.size()==0){
					if(f==1) z=i;
					l+=t[i];
					f=0;
					k="";
				}
				else l+=k;
			}
			else k+=s[i];
		}
		for(int i=1;i<=n;i++){
			if(s3[i]==l){
				string x=s.substr(z-s4[i],s1[i].size()),y=t.substr(z-s4[i],s1[i].size());
				if(x==s1[i]&&y==s2[i]) sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
