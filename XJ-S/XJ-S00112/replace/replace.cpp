#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,k;
string s[N][2];
string t[N][2];
long long num;
void dfs(string a,string b){
	
	for(int i=0;i<n;i++){
		int x=a.find(s[i][0]);
		if(x<5000100){
			int len=s[i][0].length();
			int xb=0;
			string c=a;
			for(int j=x;j<x+len;j++){
				a[j]=s[i][1][xb];
				xb++;
			}
			if(a==b)
				num++;
			a=c;
		} 
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int a=0;a<n;a++)
		for(int b=0;b<2;b++)
			cin>>s[a][b];
	for(int a=0;a<k;a++)
		for(int b=0;b<2;b++)
			cin>>t[a][b];
	for(int i=0;i<k;i++){
		num=0;
		dfs(t[i][0],t[i][1]);
		cout<<num<<endl;
	}
	return 0;
}
