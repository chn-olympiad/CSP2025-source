#include<iostream>
#include<map>
using namespace std;
int n,q,ans;
string s[200005],s1[200005],bj,bj1;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string sr,mb;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
		if((bj.find(s[i])!=bj.npos&&bj1.find(s1[i])!=bj1.npos)&&bj.find(s[i])==bj1.find(s1[i])){
			i--;
			n--;
		}
	}
	for(int qq=1;qq<=q;qq++){
		ans=0;
		cin>>sr>>mb;
		for(int i=1;i<=n;i++){
			int qsd=0;
			if(sr.find(s[i])!=sr.npos){
				string sr1=sr;
				int xb=sr.find(s[i]);
				sr1.replace(xb,s[i].size(),s1[i]);
				if(sr1==mb) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
