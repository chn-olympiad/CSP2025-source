//刘睿  SN-S00081  西安铁一中滨河高级中学
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std;
string s[200010][3],s1,s2;
int m,n,ans[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>s[i][1]>>s[i][2];
	}for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=1;j<=m;j++){
			if(s1.find(s[j][1])&&s2.find(s[j][2])&&s1.find(s[j][1])==s2.find(s[j][2])){
				ans[i]++;
			}
		}
	}for(int i=1;i<=n;i++)cout<<"0"<<endl;
	return 0;
}
