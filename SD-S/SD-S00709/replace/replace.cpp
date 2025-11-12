#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1,s2;
map<string,string>a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		a[s1]=s2;
	}
	while(q--){
		cnt=0;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();++i){
			for(int j=i;j<s1.size();++j){
				if(s1.substr(0,i)+a[s1.substr(i,j-i+1)]+s1.substr(j+1,n-j)==s2) ++cnt;
			}
		}
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
