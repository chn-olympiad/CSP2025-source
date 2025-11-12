#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[200001][3],t[2000001][3];
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t[i][1]>>t[i][2];
		int len=t[i][1].size();
		for(int l=0;l<len;l++){
			for(int siz=1;siz<=len-1-l;siz++){
				string p="";
				for(int j=l;j<l+siz;j++){
					p+=t[i][1][j];
				}
				for(int j=1;j<=n;j++){
					if(p==s[j][1]){
						string N="";
						for(int k=0;k<=l;k++){
							N+=t[i][1][k];
						}
						N+=p;
						for(int k=l+siz;k<=len;k++){
							N+=t[i][1][k];
						}
						if(N==t[i][2]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
