#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[100100],s2[100100],s,ss,st1,st2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n<=200){
		while(q--){
			int cnt=0;
			cin>>s>>ss;
			st1=s,st2=ss;
			for(int i=1;i<=n;i++){
				int k=s.find(s1[i]);
				if(k==-1) continue;
				for(int j=k;j<=k+s1[i].size()-1;j++){
					s[j]=s2[i][j-k];
				}
				if(s==ss) cnt++;
				s=st1,ss=st2;
			}
			cout<<cnt<<"\n";
		}
	}
	else{
		while(q--){
			bool flag=1;
			int cnt=0;
			cin>>s>>ss;
			for(int i=1;i<=n;i++){
				int k=s.find(s1[i]);
				if(k==-1) continue;
				for(int j=k;j<=k+s1[i].size()-1;j++){
					if(s2[i][j-k]!=ss[j]){
						flag=0;
						break;
					}
					if(ss[j]=='b'){
						break;
					}
				}
				if(flag) cnt++;
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
