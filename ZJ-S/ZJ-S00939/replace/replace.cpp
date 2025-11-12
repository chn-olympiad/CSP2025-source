#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;string s[N][3],t[3];
int find(string s1,string s2){
	int l1=s1.size(),l2=s2.size();
	if(l1<l2)
		return l1;
	for(int i=0;i<l1-l2+1;i++)
		if(s1[i]==s2[0])
			for(int j=0;j<=l2;j++){
				if(j==l2)return i;
				if(s1[i+j]!=s2[j])break;
			}
	return l1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--){
		cin>>t[1]>>t[2];
		int sum=0;
		if(t[1].size()!=t[2].size()){
			cout<<sum<<'\n';
			continue;
		}
		int l=t[1].size();
		for(int i=1;i<=n;i++){
			int f=find(t[1],s[i][1]);
			if(f!=l){
				string now=t[1];
				for(int j=0;j<s[i][2].size();j++)
					now[f+j]=s[i][2][j];
				if(now==t[2])
					sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}