#include<bits/stdc++.h>
using namespace std;
vector<char>a[100010],b[100010];
char s[100010],t[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>(s+1);
		int l=strlen(s+1);
		for(int j=1;j<=l;j++)a[i].push_back(s[j]);
		cin>>(s+1);
		for(int j=1;j<=l;j++)b[i].push_back(s[j]);
	}
	for(int i=1;i<=q;i++){
		cin>>(s+1)>>(t+1);
		int l=strlen(s+1);
		int x=l,y=0;
		for(int i=1;i<=l;i++){
			if(s[i]!=t[i]){
				x=min(x,i);
				y=max(y,i);
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=l-a[i].size()+1;j++){
				int f=0;
				for(int k=0;k<a[i].size();k++){
					if(a[i][k]!=s[j+k]||b[i][k]!=t[j+k]){
						f=1;
						break;
					}
				}
				if(!f&&x>=j&&y<=j+a[i].size()-1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

