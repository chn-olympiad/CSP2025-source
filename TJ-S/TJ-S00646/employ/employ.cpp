#include<bits/stdc++.h>
using namespace std;
int a[505];
int maxn,sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],a[i-1]);
	}
	for(int i=1;i<=n;i++){
		if(maxn==a[i]){
			sum++;
		}
		if(s[i]=='0'){
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//»ú¸ç²»Òª°¡£¡£¡£¡ 
