//SN-S00617 贾章泽 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		string t[3];
		cin>>t[1]>>t[2];
		int m=t[1].length(),m1=t[2].length(),c=0;
		if(m!=m1){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<m;i++){
			for(int j=1;j<=n;j++){
				int l=s[j][1].length();
				int flag=1;
				for(int k=0;k<i;k++) if(t[1][k]!=t[2][k]){
					flag=0;
					break;
				}
				for(int k=i;k<i+l;k++) if(t[1][k]!=s[j][1][k-i]||t[2][k]!=s[j][2][k-i]){
					flag=0;
					break;
				}
				for(int k=i+l;k<m;k++) if(t[1][k]!=t[2][k]){
					flag=0;
					break;
				}
				c+=flag;
			}
		}
		cout<<c<<"\n";
	}
}
