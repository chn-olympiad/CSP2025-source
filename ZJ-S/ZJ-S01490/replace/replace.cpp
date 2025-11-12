#include<bits/stdc++.h>
using namespace std;

int n,q;
string s[200005][5];
string t[200005][5];
string tmp;
long long ans;

bool canexch(string a,string b,int head,int x){
	for(int i=0;i<x;i++){
		if(a[i+head]!=b[i]){
			return false;
		}
	}
	return true;
}

void exch(string a,string b,int head,int x){
	tmp=a;
	for(int i=0;i<x;i++){
		tmp[i+head]=b[i];
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	if(n>1000){
		for(int i=1;i<=q;i++){
			cout<<0;
			if(i!=q){
				cout<<endl;
			}
		}
	}
	else{
		for(int i=1;i<=q;i++){
			ans=0;
			if(t[i][1].size()!=t[i][2].size()){
				cout<<0;
				if(i!=q){
					cout<<endl;
				}
				continue;
			}
			else{
				for(int j=1;j<=n;j++){
					if(t[i][1].size()<s[j][1].size()){
						continue;
					}
					for(int k=0;k<=t[i][1].size()-s[j][1].size();k++){
						if(canexch(t[i][1],s[j][1],k,s[j][1].size())){
							exch(t[i][1],s[j][2],k,s[j][1].size());
							if(tmp==t[i][2]){
								ans++;
							}
						}
					}
				}
				cout<<ans;
				if(i!=q){
					cout<<endl;
				}
			}
		}
	}
	return 0;
}