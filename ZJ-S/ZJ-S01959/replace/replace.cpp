#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[500],s2[500];
long long x[500],y[500];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<n+1;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		int xx,yy;
		for(int i=0;i<a.size() && i<b.size();i++){
			if(a[i]!=b[i]){
				xx=i;
				break;
			}
		}
		for(int i=0;i<a.size() && i<b.size();i++){
			if(a[a.size()-1-i]!=b[b.size()-1-i]){
				yy=i;
				break;
			}
		}	
		string r;
		for(int i=0;i<a.size();i++){
			string s;
			for(int j=0;j<i;j++) s+=a[i];
//			for(int j=i;)
			for(int j=i;j<a.size();j++){
	//	string s;
				s+=s1[j];
				for(int k=1;k<n+1;k++){
					if(s!=s1[k]) continue;
					string x=r+s+s1[k];
					for(int z=j+1;z<a.size();z++) x+=a[z];
					if(x==b) ans++;
				}
			}
			r+=s[i];
		}
		cout<<ans<<endl;
	}
}
