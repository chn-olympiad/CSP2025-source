#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	string s;
	int n,m,x=0,y=1,z=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	if(s[i]==b){
		cout<<" "<<"1";
	}
	b=a[i];
	sort(a+1,a+1+m+n);
	for(int i=1;i<=n;i++){
		if(a[i]==b){
			y=(y-1)+x/n;
			z=ans%n+z;
		}else{
			x++;
		}
	}
	cout<<y<<" "<<z;
	return 0;
}
