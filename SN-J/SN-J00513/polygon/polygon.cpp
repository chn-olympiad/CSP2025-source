#include<bits/stdc++.h>
using namespace std;
int s[5005];
int a[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int ans=0,h=n,flag=1;
	if(n==3){
		if((s[1]+s[2]+s[3])>(2*s[3])){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
