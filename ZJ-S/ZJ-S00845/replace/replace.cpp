#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int nn,q;
	cin>>nn>>q;
	for(int i=1;i<=nn;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t;
		cin>>t;
		int ans=0;
		int n=t.size();
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				string x=t.substr(1,i-1),
				y=t.substr(i,j-i+1),z=t.substr(j,n-j+1);
				for(int k=1;k<=nn;k++){
					if(s1[k]==y) ans++;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
