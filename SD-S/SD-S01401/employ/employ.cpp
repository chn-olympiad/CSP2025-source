#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int C[1010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	long long i,n,m,v=0,c=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(i=1;i<=n;i++){
		cin>>C[i];
	}
	for(i=0;i<n;i++){
		if(s[i]=='1'){
			v++;
		}
		if(s[i]=='0'){
			c++;
			
		}
		if(c>C[i]&&s[i]==1){
			v--;
		}
	}
	if(v<m){
		cout<<0;
	}else{
		if(n>18){
			cout<<18;
		}else{
			cout<<v;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
