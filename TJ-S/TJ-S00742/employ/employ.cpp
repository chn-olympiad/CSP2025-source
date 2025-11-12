#include<iostream>
#include<string>
using namespace std;
int n,m,flag=0; 
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=1) flag=1;
	}
	if(!flag) cout<<0<<endl; 
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
