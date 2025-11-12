#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s[200005],s1[200005];
int n,q;
string f(string str,int st,int siz){
	string res;
	for(int i=0;i<siz;i++){
		res+=str[st+i];
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		string t,t1;
		cin>>t>>t1;
		int siz=t.size(),ans=0,l,r;
		for(int j=0;j<siz;j++){
			if(t[j]!=t1[j]){
				l=j;
				break;
			}
		}
		for(int j=siz-1;j>=0;j--){
			if(t[j]!=t1[j]){
				r=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			int sizz=s[j].size();
			for(int k=0;k<=siz-sizz;k++){
				if(f(t,k,sizz)==s[j]&&f(t1,k,sizz)==s1[j]&&k<=l&&k+sizz-1>=r){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

