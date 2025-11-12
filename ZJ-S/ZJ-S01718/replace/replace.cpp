#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			for(int j=1;j<=n;j++){
				if(a[i]==s1[j][0]){
					string t=a;
					bool f=0;
					for(int k=0;k<s1[j].size();k++){
						if(s1[j][k]!=t[i+k]||s2[j][k]!=b[i+k]){
							f=1;
							break;
						}
						t[i+k]=s2[j][k];
					}
					if(f) break;
					bool flag=0;
					for(int k=0;k<a.size();k++){
						if(t[k]!=b[k]){
							flag=1;
							break;
						}
					}
					if(!flag) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
