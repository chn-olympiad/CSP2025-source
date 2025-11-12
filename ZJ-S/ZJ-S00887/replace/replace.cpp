#include<bits/stdc++.h>
using namespace std;
int n,q;
int l[200005];
string s1[200005],s2[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].length();
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<"0\n";
			continue;
		}
		int nl=t1.length(),cnt=0;
		for(int i=0;i<nl;i++){
			for(int j=1;j<=n;j++){
				if(i+l[j]-1>=nl) continue;
				string c=t1.substr(i,l[j]);
				if(c==s1[j]){
					string re=t1.substr(0,i)+s2[j]+t1.substr(i+l[j]);
					if(re==t2){
						//cout<<i<<' '<<j<<'\n';
						cnt++;
					}
				}
			}
			if(t1[i]!=t2[i]) break;
		}
		cout<<cnt<<'\n';
	}
}