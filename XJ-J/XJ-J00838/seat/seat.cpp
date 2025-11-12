#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,a[22][22],s[500],t=1;
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(i%2!=0){
				cin>>a[i][j];
				s[t]=a[i][j];
				t++;
			}
			else{
				cin>>a[i][y-j+1];
				s[t]=a[i][y-j+1];
				t++;
			}
		}
	}
	sort(s+1,s+1+t);
	int g=s[t];
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(a[i][j]==g){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
