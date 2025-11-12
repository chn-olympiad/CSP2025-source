#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	cin >>n>>m;
	q=n*m;
	long long a[105];
	for(int i=1;i<=q;i++){
		cin >>a[i];
	}
	int u=a[1],op;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=q;i++){
		if(a[i]==u){
			op=q-i+1;
			break;
		}
	}
	if(op%m==0){
		cout<<op/m<<" "<<m;
	}else{
		cout<<op/m+1<<" "<<m-(op-1);
	}
	return 0;
}                         
