#include<bits/stdc++.h>
using namespace std;
int x[110];
int y[20][20]; 
bool abc(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int c=1;c<=n*m;c++){
		cin>>x[c];
	}
	int j=x[1];
	sort(x+1,x+m*n+1,abc);
	int c=1,d=1;
	int i=1;
	while(1){
		y[c][d]=x[i];
		if(x[i]==j){
			cout<<d<<" "<<c;
			return 0;
		}
		i++;
		if((d%2&&c==n)||(d%2==0&&c==1)){
			d++;
		}
		else if(d%2){
			c++;
		}
		else{
			c--;
		}
	}
	return 0;
}

