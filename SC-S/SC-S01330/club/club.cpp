#include<bits/stdc++.h>
using namespace std;
long long a,b,c=0,e[5]={0,0,0};
long long d[1145]={},l,o; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		long long f[8]={1,2,3,0,0,0,0};
		for(int j=1;j<=b;j++){
			for(int k=1;k<=3;k++){
				cin>>d[j]>>l>>o;
			}	
			sort(d,d+1);
			for(int k=1;k<=b/2;k++){
				c=c+d[k];
			}
		}
		cout<<c;
		c=0;
	}
	return 0;
}