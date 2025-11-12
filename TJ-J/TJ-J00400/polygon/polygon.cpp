#include<bits/stdc++.h>
using namespace std;
int n,m,k[100000],v,b;
string a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	for(int i=0;i<n;i++){
		v+=i;
		if(k[i]+k[i+1]>k[i+2]){
			m++;
		}
		if(n>4+b&&v>=6){
			m+=v+n-4;
			b++;
		}
	}
	cout<<m-2;
		
	return 0;
}

