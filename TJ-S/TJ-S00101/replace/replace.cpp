#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
int ans=0;
string s[int(2e5+10)][3];
string t1,t2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		//cout<<t1<<' '<<t2<<"-------------"<<endl;
		for (int i=1;i<=n;i++){
			if (t1.find(s[i][1])<=t1.size()){
				//cout<<s[i][1]<<' '<<s[i][2]<<endl;
				int weizhi=t1.find(s[i][1]);
				string t3;
				if (weizhi+s[i][1].size()>=t1.size()){
					t3=t1.substr(0,weizhi)+s[i][2];
				}else{
					t3=t1.substr(0,weizhi)+s[i][2]+t1.substr(weizhi+s[i][1].size());
				}
				
				//cout<<t3<<"&&&&&&&"<<endl;
				if (t3==t2){
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
