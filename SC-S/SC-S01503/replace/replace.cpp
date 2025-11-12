#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s1[200005],s2[200005];
int len[200005];
string str1,str2,t;
int len1,len2,ans,val;
int n,q;
void change(int& index,string& str,string& to){
	int len1=str.size(),len2=to.size();
	for(int i=index,j=0;j<len2;i++,j++){
		str[i]=to[j];
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	for(int j=1;j<=q;j++){
		ans=0;
		cin>>str1>>str2;
		len1=str1.size(),len2=str2.size();
		if(len1!=len2){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			val=str1.find(s1[i]);
			if(0<=val&&val<=len1-len[i]+1){
				t=str1;
				change(val,t,s2[i]);
				if(t==str2) ans++;
			}
		}
		printf("%d\n",ans);
	}
}