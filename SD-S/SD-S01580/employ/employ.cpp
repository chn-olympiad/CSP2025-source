#include<bits/stdc++.h>
using namespace std;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m,flag=1;
	cin>>n>>m>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0')flag=0;
	}
	long long ncancel=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			ncancel+=1;
		}else if(c[i]<=ncancel){
			ncancel+=1;
			c[i]=0;
		}
	}
	if(flag){
		long long sans=1;
		for(int i=2;i<=n-ncancel;i++){
			sans*=i;
		}
		cout<<sans;
		return 0;
	}if(n==m&&ncancel>0){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
