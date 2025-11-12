#include<bits/stdc++.h>
using namespace std;
int n,m,a=0;
string s[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	for(int i=1;i<=n;i++){
		if(s=='0'){
			a++;
		}else{
			a=0;
		}
		
	} 
	fclose(stdin);
	fclose(stdout);
}
