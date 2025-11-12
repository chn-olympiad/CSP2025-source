#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
string s[10001],d[10001];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	} 
	for(int i=1;i<=m;i++){
		string t;
		string f;
		cin>>t>>f;
		int c=0;
		for(int j=1;j<=n;j++){
			int len=s[j].size();
			for(int l=0;l<n-len+1;l++){
				for(int r=0;r<len;r++){
					if(s[j][r]!=t[l+r])	break;
					if(r==len-1){
						if(t.substr(0,l)+d[j]+t.substr(l+r+1,n-l-r)==f)	c++;
					}
				}
			}
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
please remember to
*/
