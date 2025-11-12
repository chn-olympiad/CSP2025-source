#include<bits/stdc++.h>
using namespace std;
bool isp(int n){
	if(n%2 == 0){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1001] = { };
	int p = 1;
	cin>>a[1];
	for(int i = 2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			p+=1;
		}
	}
	int n1 = 0;
	int m1 = 0;
	int n2 = p%n;
	int m2 = p/n;
	if(n2 != 0){
		m1 = m2+1;
		if(isp(m1)){
			n1 = n+1-n2;
		}
		else{
			n1 = n2;
		}
	}
	else{
		m1 = m2;
		if(isp(m1)){
			n1 = 1;
		}
		else{
			n1 = n;
		}
	}
	cout<<m1<<" "<<n1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
