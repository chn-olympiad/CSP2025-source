#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n][2],t[q][2];
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
		
	} 
	for(int i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size()){
			cout<<0<<endl;
			continue;
		}
		long long ans=0;
		for(int j=0;j<n;j++){
			for(int k=0;k+s[j][1].size()<t[i][1].size();k++){
				bool a=1;
				for(int l=k;l<k+s[j][1].size();l++){
					if(t[i][0][l]!=s[j][0][l-k]){
						a=0;
						break;
					}
				}
				if(!a){
					continue;
				}
				string b=t[i][0];
				for(int l=k;l<k+s[j][1].size();l++){
					t[i][0][l]=s[j][1][l-k];
					
				}
				if(b==t[i][1]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

