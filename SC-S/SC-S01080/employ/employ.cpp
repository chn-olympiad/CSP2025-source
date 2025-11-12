#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],p;
bool g=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			g=1;
			p++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	if(g==0){
		cout<<0;
		return 0;
	}
	if(p<m){
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
