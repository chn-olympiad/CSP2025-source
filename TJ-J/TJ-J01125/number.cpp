#include<bits/stdc++.h>
using namespace std;
string f,s;
int a[10000],n,x=0,y=0;
int main(){
	/*
	freopen("number.in","r",stdin);
	fropen("number.out","w",stdout);
	*/
	cin>>s;
	for(int i=0;i<s.length();i++){
		//cout<<i;
		if(s[i]>='A' and s[i]<='Z'){
			f=s[i]-'A'+1;
			if(f[i]>y){
				f[i]=y;
			}
		}
		if(s[i]>='a' and s[i]<='z'){
			f=s[i]-'a'+1;
			if(f[i]>y){
				f[i]=y;
			}
		}
		
	}
	cout<<f;
	return 0;
	/*
	fclose(stdin);
	fclose(stdout);
	*/
}
