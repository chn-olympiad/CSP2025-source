#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector<vector<string> > s;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	s.resize(n,vector<string>(2));
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string t1,t2;
		int cnt=0;
		cin>>t1>>t2;
		if(t1==t2){
			cnt++;
			for(int i=0;i<n;i++)if(s[i][0]==s[i][1])cnt++;
			printf("%d\n",cnt);
			continue;
		}
		unsigned int dif=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i])dif++;
		}
		for(int i=0;i<n;i++){
			if(s[i][1].size()>t2.size())continue;
			if(s[i][0]==s[i][1]&&dif>0)continue;
			if(s[i][1].size()<dif)continue;
			if(s[i][0]==t1&&s[i][1]==t2){
				cnt++;
				continue;
			}
			for(int j=0;j<=t1.size()-s[i][1].size();j++){
				if(t1[j]==s[i][0][0]&&t2[j]==s[i][1][0]){
					bool t=true;
					string tmp1=t1;
					for(int k=j;k<j+s[i][1].size();k++){
						if(tmp1[k]!=s[i][0][k-j]||s[i][1][k-j]!=t2[k]){
							t=false;
							break;
						}
						tmp1[k]=s[i][1][k-j];
					}
					if(t&&tmp1==t2){
						cnt++;
						break;
					}	
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
