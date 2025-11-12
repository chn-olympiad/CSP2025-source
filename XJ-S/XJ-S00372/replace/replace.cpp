#include<bits/stdc++.h>
using namespace std;
string s[200005][3];
int cnt=0;
int n,q;
void B(){
	vector<int>t1(5000007,0);
	vector<int>t2(5000007,0);
	for(int i=1;i<=n;++i){
		string s1,s2;
		int b1=0,b2=0;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();++i){
			if(s1[i]=='b'){
				b1=i;
				if(b2)break;
			}
			if(s2[i]=='b'){
				b2=i;
				if(b1)break;
			}
		}
		if(b1>b2)++t1[b1-b2];
		else ++t2[b2-b1];
	}
	for(int i=1;i<=q;++i){
		string s1,s2;
		int b1=0,b2=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<s1.size();++i){
			if(s1[i]=='b'){
				b1=i;
				if(b2)break;
			}
			if(s2[i]=='b'){
				b2=i;
				if(b1)break;
			}
		}
		if(b1>b2)cout<<t1[b1-b2]<<'\n';
		else cout<<t2[b2-b1]<<'\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>10000&&q>10000){
		B();
		return 0;
	}
	for(int j=1;j<=n;++j){
		string s1,s2;
		int ii,jj;
		s[j][2]=s[j][1]="";
		cin>>s1>>s2;
		if(s1==s2){
			--j;
			--n;
			continue;
		}
		for(int i=0;i<s1.size();++i){
			if(s1[i]!=s2[i]){
				ii=i;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;--i){
			if(s1[i]!=s2[i]){
				jj=i;
				break;
			}
		}
		for(int i=ii;i<=jj;++i){
			s[j][1]=s[j][1]+" ";
			s[j][2]=s[j][2]+" ";
			s[j][1][i-ii]=s1[i];
			s[j][2][i-ii]=s2[i];
		}
	}
	for(int j=1;j<=q;++j){
		cnt=0;
		string s1,s2,t1="",t2="";
		int ii,jj;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<s1.size();++i){
			if(s1[i]!=s2[i]){
				ii=i;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;--i){
			if(s1[i]!=s2[i]){
				jj=i;
				break;
			}
		}
		for(int i=ii;i<=jj;++i){
			t1=t1+" ";
			t2=t2+" ";
			t1[i-ii]=s1[i];
			t2[i-ii]=s2[i];
		}
		for(int i=1;i<=n;++i){
			if(t1==s[i][1]&&t2==s[i][2]){
				++cnt;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 
