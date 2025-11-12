#include<bits/stdc++.h>
using namespace std;
string s[200005][5];
int b[200005][5]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int l=0,r=0;
		while(s[i][1][l]!='b')l++;
		while(s[i][2][r]!='b')r++;
		b[i][1]=l;
		b[i][2]=r;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int l=0,r=0;
		while(t1[l]!='b')l++;
		while(t2[r]!='b')r++;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(l>=b[i][1]&&r-l==b[i][2]-b[i][1]&&s[i][1].size()-b[i][2]>=t1.size-r)ans++;
		}
		cout<<ans<<endl;
	}
} 
