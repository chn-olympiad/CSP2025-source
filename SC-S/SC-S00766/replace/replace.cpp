#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,q;
string a[N][2];
string b[N][2];
string change(string x,string y,int j){
	int cnt=0;
	for(int i=0;i<y.size();i++){
		while(x[i+cnt]!=y[i]){
			cnt++;
		}
	}
//	cout<<cnt<<endl;
	string tmp="";
	for(int i=0;i<cnt;i++)tmp+=x[i];
	tmp+=a[j][2];
	for(int i=cnt+a[j][1].size();i<x.size();i++)tmp+=x[i];
	return tmp;
}
int main() {
	freopen("r","in","replace.in");
	freopen("w","out","replace.out");
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<q;i++){
		cin>>b[i][1]>>b[i][2];
	}
	for(int i=0;i<q;i++){
		int ans=0;
		for(int j=0;j<n;j++){
			string tmp=change(b[i][1],a[j][1],j);
//			cout<<tmp;
			if(tmp==b[i][2])ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
//1 1
//bc de
//xabcx xadex

//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a
