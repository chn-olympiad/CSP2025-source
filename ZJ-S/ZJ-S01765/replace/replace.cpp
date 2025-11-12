#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][2];
int st[N],ed[N];
string s1,s2;
inline bool check(int k,int str){
	if(str<0)return 0;
	if(str+s[k][0].size()>s1.size())return 0;
	for(int i=str,j=0;j<s[k][0].size();i++,j++){
		if(s[k][0][j]!=s1[i]||s[k][1][j]!=s2[i])return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int stl=-1,edl=-2;
		int len=s[i][0].size();
		for(int j=0;j<len;j++){
			if(s[i][0][j]!=s[i][1][j]){
				edl=j;
				if(stl==-1)stl=j;
			}
		}
		st[i]=stl;
		ed[i]=edl;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int st1=-1,ed1=-2;
		int len=s1.size();
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]){
				ed1=i;
				if(st1==-1)st1=i;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((ed1-st1)==(ed[i]-st[i])){
				if(check(i,st1-st[i])){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}