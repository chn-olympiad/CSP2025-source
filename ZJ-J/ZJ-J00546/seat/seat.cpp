#include<bits/stdc++.h>
using namespace std;
int n,m,a[178],r,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;cin>>a[1];r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>r){
			s++;
		}
	}
	if((s+n-1)/n%2==1){
		cout<<(s+n-1)/n<<" ";
		if(s%n==0)cout<<n;
		else cout<<s%n;
	}
	else{
		cout<<(s+n-1)/n<<" ";
		if(s%n==0)cout<<1;
		else cout<<n-s%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//O(n)
