#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s[200005][2],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<m;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
		}else{
			long long h=0;
			string ss="";
			for(int j=0;j<n;j++){
				if(int(s1.find(s[j][0]))!=-1){
					int d=s1.find(s[j][0]);
					if(s1.substr(0,d)+s[j][1]+s1.substr(d+s[j][1].size())==s2){
						h++;
					}
				}
			}
			cout<<h<<endl;
		}
	}
	return 0;
}
