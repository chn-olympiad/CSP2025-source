#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int c,k;
	string s1,s2;
}s[1000001];
int n,m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
		int x,y;
		for(int j=0;j<s[i].s1.length();j++){
			if(s[i].s1[j]=='b')x=j;
			if(s[i].s2[j]=='b')y=j;
		}
		s[i].k=x;
		s[i].c=x-y;
	}
	while(m--){
		string a,b;
		cin>>a>>b;
		int x,y;
		for(int i=0;i<a.length();i++){
			if(a[i]=='b')x=i;
			if(b[i]=='b')y=i;
		}
		int z=x-y,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i].c==z&&s[i].s1.length()+x-s[i].k<=a.length()&&s[i].k<=x)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
