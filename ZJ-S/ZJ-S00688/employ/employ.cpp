#include <bits/stdc++.h>
using namespace std;
int pa[505];
int main(){
	int n,m;
	cin>>n>>m;
	int f=0,flag;
	char ch,cnt=0;
	while(scanf("%c",&ch)){
		cnt++;
		if(!f&&ch=='0'){
			flag=cnt-1;
			f=true;
		}
		if(cnt==n)
			break;
	}
	for(int i=1;i<=n;i++)
		cin>>pa[i];
	if(m>flag){
		cout<<0;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i+998244353)%998244353;
		}
		cout<<ans;
	}
	return 0;
}