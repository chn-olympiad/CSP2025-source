#inculde<bits/stdc++.h>
using namespace std;
int main{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int he=0;
    cin<<n,m;
    cin<<a;
	for(int i;i<=n*m-1;i++){
		cin<<i;
		if(i>a){
			he+1;
		}
	}
	cout>>n*m/he;
	if(n==1&&m==1){
		cout>>"1">>" ">>"1";
	}
}
