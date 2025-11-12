#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		for(int i=1;i<=n;i++){
			if(s1.find(s[i][1])){
				string s3=s1;
				for(int j=0;j<len;j++){
					if(s1[j]==s[i][1][0]){
						while(s1[j]==s[i][1][j]){
							s1[j]=s[i][2][j];
						}
						break;
					}
				}
				if(s1==s2){
					ans++;
				}
				s1=s3;
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
}
