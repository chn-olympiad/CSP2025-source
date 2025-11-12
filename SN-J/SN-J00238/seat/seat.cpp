#include<bits/stdc++.h>
using namespace std;
int n,m,s,bj;
int a[105],c[105][105];

bool f(int a,int b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	int b = n*m;
	cin>>s;
	a[1] = s;
	for(int i = 2;i<=b;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+b,f);

	int i = 1,j = 1,cnt = 1;
	for(int k = 1;k<=b;k++){
		c[i][j] = a[cnt];
		
		if(c[i][j] == s){
			cout<<j<<" "<<i;
			break;
		}
		if(i+1<= n && c[i+1][j] == 0){
			i++;
		}	
		else if(i == n && j+1<=m){
			j++;
		}
		else i--;
		cnt++;
	}
}
