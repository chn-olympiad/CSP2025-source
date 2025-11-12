#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10;
string sx[N],sy[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sx[i]>>sy[i];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			
			for(int j=0;j<t1.size();j++){
				int f=1;
				for(int k=0;k<sx[i].size();k++){
					if(t1[j+k]!=sx[i][k]){
						f=0;
						break;
					}
				}
				if(f==1){
					string s="";
					for(int k=0,p=0;k<t1.size();k++){
						if(j<=k&&k<=j+sx[i].size()-1){
							s=s+sy[i][p];
							p++;
						}
						else{
							s=s+t1[k];
						}
					}
					if(s==t2)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/