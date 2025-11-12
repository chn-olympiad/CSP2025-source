#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1000][1000];
	int b[1000];
	int n,m;
	cin >> n >> m;
	for(int i=0;i<=n*m;i++){
		cin >> b[i];
	} 
	int a1 = b[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
		   if(b[i]<b[i+1]){
			 swap(b[i],b[i+1]);
	       }	
		}	
	}
	for(int p=0;p<=n;p++){
		for(int o=0;o<=m;o++){
			a[p][o]=b[p];
			if(a[p][o]==a1){
				cout << p << " " << o;
				return 0;
			}
		}
	}
	return 0;
}
