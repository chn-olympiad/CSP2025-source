#include <bits/stdc++.h>
using namespace std;
int n,m,c[510];
string s;
int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int cnt=0,ant=0,a=0;
	for(int i=1;i<=n;i++){
		int s1=s[i];
		if(c[i]==cnt||c[i]>cnt){
			cnt++;
			if(s1==1) ant--;
		}
		if(s1==0) cnt++;
		if(s1==1) ant++;
		if(ant==m) a++;
	}
	return 0;
}