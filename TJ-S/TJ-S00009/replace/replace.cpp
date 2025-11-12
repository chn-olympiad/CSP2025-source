#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int cha[N];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int aaa=0,bbb=0;
		for(int j=0;j<max(a[i].length(),b[i].length());j++){
			if(a[i][j]=='b')
				aaa=j;
			if(b[i][j]=='b')
				bbb=j;
		}
		cha[i]=aaa-bbb;
	}
	while(m--){
		string s,t;
		cin>>s>>t;
		int aaa=0,bbb=0,sum=0;
		for(int j=0;j<max(s.length(),t.length());j++){
			if(s[j]=='b')
				aaa=j;
			if(t[j]=='b')
				bbb=j;
		}
		int ch=aaa-bbb;
		for(int i=1;i<=n;i++){
			sum+=(cha[i]==ch);
		}
		cout<<sum<<endl;
	}
	return 0;
}


