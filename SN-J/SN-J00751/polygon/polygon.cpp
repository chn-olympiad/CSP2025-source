#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,sum=0,l=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >>m;
		if(m>l){
			l=m;
		}
		sum=sum+m;
	}
	if(sum>=l*2){
		cout <<1;
		
	}
	else
	{
		cout <<0;
	}
	return 0;
}
