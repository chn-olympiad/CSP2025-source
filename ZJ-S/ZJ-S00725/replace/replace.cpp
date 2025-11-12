#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ans,k;
string s1[200005],s2[200005],c1,c2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	for(;m--;ans=0){
		cin>>c1>>c2;
		if(c1.length()!=c2.length()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<n;i++){
			k=c1.length()-s1[i].length()+1;
			for(int j=0;j<k;j++){
				if(c1.substr(j,s1[i].length())==s1[i])ans+=(c1.substr(0,j)+s2[i]+c1.substr(j+s1[i].length())==c2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
