#include<bits/stdc++.h>
using namespace std;
int n,q,s,fl;
string s1[100001],s2[100001],t1[100001],t2[100001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		s=0;
		cin>>t1[i]>>t2[i];
		int l=t1[i].size();
		
		for(int j=1;j<=n;j++){
			fl=1;
			if(t1[i].find(s1[j])==t2[i].find(s2[j])&&t1[i].find(s1[j])<l){
				for(int k=0;k<t1[i].find(s1[j]);k++){
					if(t2[j][k]!=t1[j][k]){
						fl=0;
						break;
					}
				}
				for(int k=t1[i].find(s1[j])-1;k<t1[i].size();k++){
					if(t2[j][k]!=t1[j][k]){
						fl=0;
						break;
					}
				}
			}else fl=0;
			if(fl) s++;
		}
		cout<<s<<endl;
	}
	
	return 0;
}
