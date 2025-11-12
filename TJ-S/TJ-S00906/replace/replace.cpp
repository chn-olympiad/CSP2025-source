#include <bits/stdc++.h>
using namespace std;
int n,q;
string str[200010];
map<string,string> mp;
int dfs(string s1,string s2){
	int ans=0,len=s1.length();
	for(int i=1;i<=n;i++){
		int l=str[i].length();
		for(int j=0;j<len&&j+l<=len;j++){
			bool flag=0;
			for(int k=0;k<l;k++)if(s1[j+k]!=str[i][k]){flag=1;break;}
			if(flag)continue;
			string t=s1,rep=mp[str[i]];
			for(int k=j;k<j+l;k++){
				t[k]=rep[k-j];
			}
			for(int k=j+l;k<len;k++)t[k]=s1[k];
			
			if(t==s2)ans++;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		str[i]=s1;
		mp[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		cout<<dfs(s1,s2)<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

