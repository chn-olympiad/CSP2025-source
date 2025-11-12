#include<bits/stdc++.h>
using namespace std;
int a[10010];
int maxn=-1, z, cnt;
int main(){
	freopen("number.in", "r",stdin);
	freopen("number.out", "w",stdout);
	string x;
	cin>>x;
	for(int i=0; i<x.size(); i++){
		if(x[i]<='9' && x[i]>='0'){
			a[i]=x[i]-'0';
			cnt++;
		}
	}
	for(int i=1; i<=cnt; i++){
		for(int j=0; j<cnt; j++){
			if(a[j]>maxn){
				maxn=a[j];
				z=j;
			}	
		}
		a[z]=0;
		z=0;
		cout<<maxn;
		maxn=-1;
	}
	cout<<endl;
	return 0;
} 
