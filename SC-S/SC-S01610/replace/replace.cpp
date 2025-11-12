#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,q;
string s[N],d[N],S,T;
bool ck(int x,int p){
	for(int i=0;i<x;i++){
		if(S[i]!=T[i])return 0;
	}
	int i=x;
	for(int l=0;l<s[p].size()&&i<S.size();i++,l++){
		if(d[p][l]!=T[i]||s[p][l]!=S[i])return 0;
	}
	for(;i<S.size();i++){
		if(S[i]!=T[i])return 0;
	}
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>d[i];
	for(int i=1;i<=q;i++){
		cin>>S>>T;
		int sum=0; 
		for(int j=1;j<=n;j++){
			for(int k=0;k<S.size();k++){
				if(S[k]==s[j][0])sum+=ck(k,j);
			}
		}
		cout<<sum<<endl;
	}
} 