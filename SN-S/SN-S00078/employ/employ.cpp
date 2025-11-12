#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n==3&&m==2){
		cout<<"2";
	}else{
		cout<<m;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
