#include<bits/stdc++.h>
using namespace std;
long long n=0,q=0,m=0,a[1000],t=0,p=0;
string s;
int main(){
	freopen("employ.in",'r',stdin);
	freopen("employ.out",'w',stdout);
	cin>>m>>n>>s;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			q++;
		}
		else if(s[i]=='1'){
			p++;
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		if(a[i]<p){
			t++;
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
