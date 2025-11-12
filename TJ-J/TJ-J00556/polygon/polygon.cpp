#include<bits/stdc++.h>
using namespace std;
int l[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s,x=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int h=3;h<=n;h++){
		for(int i=0;i<n;i++){
			s+=l[i];
		}
		if(s>2*l[h]){
			x++;
		}
	}
	cout<<x;
	return 0;
}
