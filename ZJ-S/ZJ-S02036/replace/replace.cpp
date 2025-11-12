#include<bits/stdc++.h>
using namespace std;
string lst[200010][2];
int n,q,lsi[200010][2];
string cut(string s,int beg,int end){
	string ans="";
	for(int i=beg;i<end && i<s.size();i++){
		ans+=s[i];
	}
	return ans;
}
void solve(string s1,string s2){
	string st,ans;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s2.size()<lst[i][1].size()) continue;
		for(int j=0;j<=s2.size()-lst[i][1].size();j++){
			if(s2[j]==lst[i][1][0]){
				st=cut(s2,j,j+lst[i][1].size());
				if(st==lst[i][1]){
					ans=cut(s2,0,j)+lst[i][0]+cut(s2,j+lst[i][1].size(),s2.size());
					if(ans==s1) cnt++; 
				}
			}
		}
	}
	cout<<cnt<<"\n";
	return;
}
void solve2(string s1,string s2){
	int s1i,s2i,cnt=0;
	for(int j=0;j<s1.size();j++){
		if(s1[j]=='b'){
			s1i=j;
			break;
		}
	}
	for(int j=0;j<s2.size();j++){
		if(s2[j]=='b'){
			s2i=j;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(	s1i-lsi[i][0]+lsi[i][1]==s2i && \
			s1i-lsi[i][0]>=0 && \
			s1.size()-lst[i][0].size()+lst[i][1].size()==s2.size() && \
			(s1.size()-s1i-lst[i][0].size()+lsi[i][0])>=0){
				cnt++;
				//cerr<<i<<" "<<s1<<" "<<s1i<<" "<<lst[i][0]<<" "<<lsi[i][0]<<"\n";
			}
	}
//	cerr<<"\n";
	cout<<cnt<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,f=1;
	string s1,s2;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		cin>>s1>>s2;
		if(s1!=s2){
			lst[i][0]=s1;
			lst[i][1]=s2;
		}
		else{
			n--;
			i--;
		}
		if (98<s1[0]) f=0;
	}
	if(f){
		for(i=0;i<n;i++){
			for(int j=0;j<lst[i][0].size();j++){
				if(lst[i][0][j]=='b'){
					lsi[i][0]=j;
					break;
				}
			}
			for(int j=0;j<lst[i][1].size();j++){
				if(lst[i][1][j]=='b'){
					lsi[i][1]=j;
					break;
				}
			}
		}
		for(i=0;i<q;i++){
			cin>>s1>>s2;
			solve2(s1,s2);
		}
		return 0;
	}
	for(i=0;i<q;i++){
		cin>>s1>>s2;
		solve(s1,s2);
	}
	return 0;
}

