#include<bits/stdc++.h>
using namespace std;
string s[100001][2],t[100001][2];
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++){
		if(t[i][0].size()!=t[i][1].size()){
			printf("0\n");
			continue;
		}
		int l=t[i][0].size(),r=0;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!=t[i][1][j])
				l=min(l,j),r=max(r,j);
		}
		for(int j=0;j<=l;j++){
			for(int k=r;k<t[i][0].size();k++){
				if(qj(t[i][0],j,k)==)
			}
		}
	}
	return 0;
}
