//SN-S00728 闫卜予 西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n,m;
bool s[514];
int c[514];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>cc;
		s[i]=(cc=='0');
		if(m==n&&cc=='0'){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	
	sort(c+1,c+m+1);
	return 0;
} 
