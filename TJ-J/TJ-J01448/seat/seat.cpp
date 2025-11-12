#include<bits/stdc++.h>
using namespace std;
int a[100];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m>>s;
	a[1]=s;
	for (int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int j=0;
	for (int i=1;i<=n*m;i++){
		if (a[i]==s)
		    j=i;
	}
	if (j/m>m){
		cout<<m<<" ";
	}
	else
		cout<<j/m<<" ";
	if (j%n==0){
		cout<<n<<" ";
	}
	else
		cout<<j%n<<" ";
	return 0;
}
