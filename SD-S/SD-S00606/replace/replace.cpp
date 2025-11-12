#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,cnt;
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		bool flag=true;
		for(int j=1;j<=cnt;j++){
			if(s[j][1]==s1&&s[j][2]==s2){
				flag=false;
				break;
			}
		}
		if(flag==true){
			++cnt;
			s[cnt][1]=s1;
			s[cnt][2]=s2;
		}
	}
	while(q--){
		string start,end;
		int ans=0;
		cin>>start>>end;
		for(int i=1;i<=cnt;i++){
			for(int j=0;j+s[i][1].size()<=start.size();j++){
				string s1=start.substr(0,j);
				string s2=start.substr(j,s[i][1].size());
				string s3=start.substr(j+s[i][1].size());
				if(s2==s[i][1]&&s1+s[i][2]+s3==end){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
