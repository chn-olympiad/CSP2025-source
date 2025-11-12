#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,r;long long t;
int cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;long long a[n*m+1]={};
	for (int i=0;i<n*m;i++) cin>>a[i];
	k=a[0];sort(a,a+n*m,cnt);
	for (int i=0;i<n*m;i++) if (a[i]==k) t=i+1;
	if (t%n==0) c=t/n;
	else c=t/n+1;
	if (c%2==1){
		if (t%n==0) r=t;
		else r=t%n;
	} 
	else r=n-(t%n)+1;
	cout<<c<<" "<<r;
	fclose(stdin);fclose(stdout);
	return 0;
}




