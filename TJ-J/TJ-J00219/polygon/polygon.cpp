#include<bits/stdc++.h>
using namespace std;
int n;
int a[6666]; 
long long c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		while(c!=998244353){
			c++;
			if(c%998244353){
				c++;
				break;
			} 
		}
	}
	cout<<c%998244353;
	return 0;
}
