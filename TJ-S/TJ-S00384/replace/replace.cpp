#include<iostream>
using namespace std;
//Ren5Jie4Di4Ling5%
int n,q,ans;
string s[10004][2];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		ans=0;
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				int k=0;
				string tmp=t1;
				for(k=0;k<s[j][0].size()&&t1[i+k]==s[j][0][k];k++){
//					cout<<j<<' '<<k<<' '<<tmp[i+k]<<' '<<s[j][0][k]<<endl;
					tmp[i+k]=s[j][1][k];
				}
				if(k==s[j][1].size()){
					if(tmp==t2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
