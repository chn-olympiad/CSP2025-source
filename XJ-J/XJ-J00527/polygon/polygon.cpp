#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int p[n+2];
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int q=0;
	for(int i=3;i<=n;i++){
		if(p[i-1]+p[i-2]>p[i]){
			q++;
		}
	}
	for(int i=4;i<=n;i++){
		if(p[i-1]+p[i-3]>p[i]){
			q++;
		}
		if(p[i-1]+p[i-2]+p[i-3]>p[i]){
			q++;
		}
	}
	for(int i=5;i<=n;i++){
		if(p[i-1]+p[i-4]>p[i]){
			q++;
		}
		if(p[i-1]+p[i-2]+p[i-4]>p[i]){
			q++;
		}
		if(p[i-1]+p[i-3]+p[i-4]>p[i]){
			q++;
		}
		if(p[i-1]+p[i-2]+p[i-3]+p[i-4]>p[i]){
			q++;
		}
	}
	/*...*/
	cout<<q; 
	return 0;
}
