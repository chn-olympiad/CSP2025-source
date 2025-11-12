#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int m[N];
char a[N];
int tm[N];
char ta[N];
int n,q;
string s,s1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>s1;
		for(int i=0;i<s.size();){
			int len=1;
			for(int j=i+1;j<=s.size();j++){
				if(s[j]==s[i]) len++;
				else a[++m[0]]=s[i],m[m[0]]=len,i=j;
			}
		}
		a[++m[0]]='!',m[m[0]]=0;
		for(int i=0;i<s1.size();){
			int len=1;
			for(int j=i+1;j<=s1.size();j++){
				if(s1[j]==s1[i]) len++;
				else a[++m[0]]=s1[i],m[m[0]]=len,i=j;
			}
		}
		a[++m[0]]='?',m[m[0]]=0;
	}
	for(int i=1;i<=q;i++){
		cin>>s>>s1;
		cout<<0<<endl;
	}
	return 0;
}
