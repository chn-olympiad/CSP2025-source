#include<bits/stdc++.h>
using namespace std;
int n,m,s[110],c[110];
int cnt=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin.tie(0);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(s[i]==1){
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
