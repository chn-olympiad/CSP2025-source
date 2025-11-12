#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][2],t1,t2;
map<string,string> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1],m[s[i][0]]=s[i][1];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())cout<<"0\n";
		else{
			int len=t1.size(),l=0,r=0;
			for(int j=0;j<=len-1;j++){
				string ss="#",xx="#",yy="#";
				ss.erase(0,1);
				xx.erase(0,1);
				yy.erase(0,1);
				if(j){
					if(t1[j-1]!=t2[j-1])break;
				}
				for(int k=0;k<j;k++)xx+=t1[k];
				for(int k=j;k<=len-1;k++)yy+=t1[k];
				for(int k=j;k<=len-1;k++){
					ss+=t1[k];
					yy.erase(0,1);
					if(xx+m[ss]+yy==t2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
