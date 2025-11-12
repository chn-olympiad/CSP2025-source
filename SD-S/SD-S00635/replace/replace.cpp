#include<bits/stdc++.h>
using namespace std;
string s1,s2,c[201000][2];
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>c[i][0]>>c[i][1];
	}
	while(q--){
		ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=s1.size();j++){
				if(c[i][0][0]==s1[j]){
					string d=s1;
					int l=0,r=j;
					while(c[i][0][l]==d[r]&&l<c[i][0].size()&&r<d.size()){
						d[r]=c[i][1][l];
						r++;
						l++;
					}
					if(l==c[i][0].size()&&d==s2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
} 
