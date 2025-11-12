#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
string strread(){
	char c=getchar();
	string sqwq="";
	while(c<'a' || c>'z'){
		c=getchar();
	}
	while(c>='a' && c<='z'){
		sqwq+=c;
		c=getchar();
	}
	return sqwq;
}
string str1[200005],str2[200005],strx,stry;
int n,q,ans;
bool ins(string I,string J,int st){
	string A="",B="",Q="";
	for(int i=0;i<st;i++){
		A+=strx[i];
	}
	for(int i=st+I.size();i<strx.size();i++){
		B+=strx[i];
	}
	for(int i=st;i<st+I.size();i++){
		Q+=strx[i];
	}
	if(Q!=I){
		return false;
	}
//	cout<<"OVO";
//	cout<<A.size()<<" "<<B.size()<<" "<<Q.size()<<endl;
//	if(A.size()+J.size()+B.size()==strx.size()){
//		cout<<"AUA"<<endl;
//	}
	return bool((A+J+B)==stry);
}
int check(){
	int qaq=0;
	for(int i=1;i<=n;i++){
//		cout<<"QWQ";
//		cout<<strx.size()-str1[i].size()<<endl;
		if(str1[i].size()>strx.size()){
			continue;
		}
		for(int j=0;j<=strx.size()-str1[i].size();j++){
//			cout<<"qwq";
//			cout<<strx.size()-str1[i].size()<<endl;
			if(ins(str1[i],str2[i],j)){
				qaq++;
			}
		}
	}
	return qaq;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		str1[i]=strread();
		str2[i]=strread();
	}
	for(;q;q--){
		strx=strread();
		stry=strread();
		if(strx.size()!=stry.size()){
			ans=0;
		}
		else{
			ans=check();
		}
		cout<<ans<<endl;
	}
	return 0;
}
