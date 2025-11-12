#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, s;
	cin>>n;
	int j[10005];
	if(n<3){
		s = 0;
	}
	else{
		for(int i = 0;i<n;i++){
			s = s+n-i;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}

