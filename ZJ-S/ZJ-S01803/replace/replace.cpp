#include<bits/stdc++.h>
using namespace std;
int n,q;
char s3[5000010];
struct st{
	string s;
}s1[200010],s2[200010];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i].s>>s2[i].s;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			return 0;
		}
		int t3=t1.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s1[i].s.size()<=t3;j++){
				int flag=1;
				for(int k=0;k<j;k++){
					if(t1[k]!=t2[k]){
						flag=0;
						break;
					}
				}
				for(int k=j+s1[i].s.size();k<t3;k++){
					if(t1[k]!=t2[k]){
						flag=0;
						break;
					}
				}
				for(int k=j;k<j+s1[i].s.size();k++){
					if(t1[k]!=s1[i].s[k-j] || t2[k]!=s2[i].s[k-j]){
						flag=0;
						break;
					}
				}
				if(flag){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
