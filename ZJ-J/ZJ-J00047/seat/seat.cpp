#include<bits/stdc++.h>
using namespace std;
int n,m,s[1100];
bool cpp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
	}
	int a=s[1],ii;
	sort(s+1,s+n*m+1,cpp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==a){
			ii=i;
			break;
		}
	}
	if((((ii-1)/n)+1)%2==1) cout<<((ii-1)/n)+1<<' '<<(ii-1)%n+1;
	else cout<<((ii-1)/n)+1<<' '<<n-((ii-1)%n);
	return 0;
}
