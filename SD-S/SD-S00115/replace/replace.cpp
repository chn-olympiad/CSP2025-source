#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,ans;
string t1,t2,s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(m--){
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int len=s[i][1].size();
			for(int j=0;j<t1.size();j++){
				if(t1.substr(j,len)==s[i][1]){
					if(t1.substr(0,j-1)+t1.substr(j,len)+t1.substr(j+len+1,t1.size()-j-len-1)==t2){
						++ans;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
