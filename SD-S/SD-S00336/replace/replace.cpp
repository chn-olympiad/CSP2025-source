#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string s[110][5],t1,t2,tl;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			tl=t1;
			for(int j=0;j+s[i][0].size()<=t1.size();j++){
				if(tl.substr(j,s[i][0].size())==s[i][0]){
					for(int k=j;k<=j+s[i][0].size()-1;k++){
						tl[k]=s[i][1][k-j];
					}
					if(tl==t2){
						ans++;
						break;
					}
					else{
						tl=t1;
					}
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
