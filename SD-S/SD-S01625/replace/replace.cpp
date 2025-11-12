#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
map<pair<string,string>,int> mp;
string str(){
	char c=getchar();
	string ans="";
	while(c<'a' || c>'z'){
		c=getchar();
	}
	while(c>='a' && c<='z'){
		ans+=c;
		c=getchar();
	}
	return ans;
}
void comp(string a,string b,int flag){
	string ta="",tb="",tc="";
	int f=1;
	for(int i=0;i<(int)a.size();i++){
		if(a[i]==b[i] && f==0){
			tc+=" ";
		}
		if(a[i]!=b[i]){
			ta+=tc+a[i];
			tb+=tc+b[i];
			tc="";
		}
	}
	if(flag==1){
		mp[make_pair(ta,tb)]++;
	}
	else{
		printf("%d\n",mp[make_pair(ta,tb)]);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		string a=str(),b=str();
		comp(a,b,1);
	}
	for(int j=1;j<=q;j++){
		string ss=str(),tt=str();
		int lens=ss.size(),lent=tt.size();
		if(lens!=lent){
			printf("0\n");
			continue;
		}
		else{
			comp(ss,tt,2);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
