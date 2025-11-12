#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int n,m;
string s1,s2;
int len;
string jq(string s,int l,int r) {
	if(r<0||l>r||l>=len)
		return "";
	string ans="";
	for(int i=l; i<=r; i++)
		ans+=s[i];
	return ans;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=1; i<=m; i++) {
		cin>>s1>>s2;
		int ans=0;
		int l,r;//不一样的区间
		len=s1.size();
		for(int j=0; j<len; j++)
			if(s1[j]!=s2[j]) {
				l=j;
				break;
			}
		for(int j=len-1; j>=0; j--)
			if(s1[j]!=s2[j]) {
				r=j;
				break;
			}
		string temp1=jq(s1,l,r);
		string temp2=jq(s2,l,r);
		//前面可以截取 l 个
		//后面可以截取 len-r-1 个
		for(int i=0; i<=l; i++) {
			for(int j=r; j<len; j++) {
				string t1=jq(s1,i,l-1)+temp1+jq(s1,r+1,j);
				string t2=jq(s2,i,l-1)+temp2+jq(s2,r+1,j);
				if(mp[t1]==t2)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
