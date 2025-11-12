#include<bits/stdc++.h>
using namespace std;
const int M=1e6+50;
const int N=1e5+50;
#define LL long long
vector<string> a;
vector<string> b;
string s1,s2;
int f(int k){
	int ans=0;
	int len=s1.length(),len1=s2.length(),lenk=a[k].length();
	if(len1!=len){
		return 0;	
	}
	if(s1==s2)	ans=1;
	for(int i=0;i<len;i++){
		int same=0;
		bool b1=1,b2=0,b3=1;
		for(int j=0;j<lenk;j++){
			if(s1[i+j]==a[k][j]&&b[k][j]==s2[i+j]&&i+j<len){
				same++;
			}
			else break;
		}
		for(int j=0;j<i;j++){
			if(s1[j]!=s2[j])	b1=0;
		}
		for(int j=i+lenk;j<len;j++){
			if(s1[j]!=s2[j])	b3=0;
		}
		if(same==lenk)	b2=1;
		if(b1&&b2&&b3)	ans++;
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		a.push_back(s1);
		b.push_back(s2);
	}
	while(q--){
		cin>>s1>>s2;
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=f(i);
		}
		printf("%d\n",ans);
	}
}
