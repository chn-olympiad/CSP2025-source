#include<bits/stdc++.h>
using namespace std;
string s;
const long long N=1e6+10;
int q[N]={0};
int p[N]={0};
long long m=0,n=0,l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48 && s[i]<=57){
			q[m++]=s[i]-48;
		}
	}
	sort(q,q+m);
	for(int i=m-1;i>=0;i--){
		p[n++]=q[i];
	}
	for(int i=0;i<n;i++){
		l=l*10+p[i];
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
