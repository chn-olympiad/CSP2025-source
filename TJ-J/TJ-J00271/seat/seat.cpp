#include<bits/stdc++.h> 
using namespace std;
int n,m,c,r;
long long a[45][45];
int b[211],l,f;

int main(){

	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> b[i];
	}cout<<n-1<<" "<<m-2;
	l = b[0];
	sort(b,b+n*m);
	reverse(b,b+n*m);
	f = 1;
	for(int i =1 ;i <= n;i++){
		f=!f;

		for(int j =1 ;j<= n;j++){
			if(f){
			
				a[i][j] = b[j];
				}
}
}
}
