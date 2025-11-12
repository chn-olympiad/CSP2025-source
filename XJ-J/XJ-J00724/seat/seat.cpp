#include<bits/stdc++.h>
using namespace std;
long long n,m,s[105],t[105],ans,p;
long long a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>s[i];
		t[s[i]]++;
	}
	p=s[1];
	ans=1;
	for(long long i=100;i>=1;i--){
		if(t[i]!=0){
			s[ans]=i;
			ans++;
		}
	}
	ans=0;
	for(long long j=1;j<=m;j++){
		if(j%2!=0){
			for(long long i=1;i<=n;i++){
				ans++;
				a[i][j]=s[ans];
			}
		}else{
			for(long long i=n;i>=1;i--){
				ans++;
				a[i][j]=s[ans];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(a[i][j]==p){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
