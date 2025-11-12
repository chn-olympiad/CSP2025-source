#include<iostream>
#include<cstring>
using namespace std;
int n,q;
string s[100005][2];
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			bool flag=true;
			if(t1.find(s[i][0])!=s[i][0].npos){
				int a=t1.find(s[i][0]);
				string str="";
				for(int j=0;j<a;j++){
					str+=t1[j];
				}
				str+=s[i][1];
				for(int j=a+s[i][0].size();j<t1.size();j++){
					str+=t1[j];
				}
				if(str==t2){
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
//expect 50pts
