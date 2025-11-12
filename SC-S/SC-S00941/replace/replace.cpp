#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s,s2;
struct node{
	string x,y;
}a[200020];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	while(q--){
		cin>>s>>s2;
		ans=0;
		for (int i=1;i<=n;i++){
			int m=-1,f=0;
			for (int j=0;j<s.size();j++){
				if(s[j]==a[i].x[0]){
					f=1;
					for(int k=j;k<=j+a[i].x.size()-1;k++){
						if(a[i].x[++m]!=s[k]){
							f=0;
							break;
						}
					}
				}
				if(f==1){
					string s3="";
					for (int k=0;k<j;k++)s3+=s[k];
					s3+=a[i].y;
					for (int k=j+a[i].x.size();k<s.size();k++) s3+=s[k];
					if(s3==s2) ans++;
					j+=a[i].x.size()-1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}