#include<iostream>
#include<cstring>
using namespace std;
int check(string s,string z){
	int flag;
	if(s.length()<z.length()){
		return -1;
	}
	for(int j=0;j<s.length()-z.length();j++){
		for(int k=0;k<z.length();k++){
			flag=0;
			if(s[k]!=z[k]){
				flag=1;
				break;
			}
		}
		if(flag==0)return j;
	}
	return -1;
}
string del(string s,int pos){
	string a;
	for(int i=s.length();i>pos;i--){
		a[i-pos]=s[i];
	}
	return a;
}
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,q;
	cin>>i>>q;
	string s[i][2],qu[q][2];
	int ans[q]={0};
	for(int j=0;j<i;j++){
		cin>>s[j][0]>>s[j][1];
	}
	for(int j=0;j<q;j++){
		cin>>qu[j][0]>>qu[j][1];
	}
	for(int j=0;j<q;j++){
		for(int k=0;k<i;k++){
			if(check(qu[j][0],s[k][0])!=-1){
				if(check(qu[j][1],s[k][1])!=-1){
					if((check(qu[j][0],s[k][0])==check(qu[j][1],s[k][1]))&&(del(qu[j][0],check(qu[j][0],s[k][0]))==del(qu[j][1],check(qu[j][1],s[k][1])))){
						ans[j]++;
					}
				}
			}
			
		}
	}
	for(int j=0;j<q;j++){
		cout<<ans[j]<<endl;
	}
	return 0;
}
