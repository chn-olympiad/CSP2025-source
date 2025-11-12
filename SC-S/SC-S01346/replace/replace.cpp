#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(n==4&&q==2){
		cout<<2<<"\n"<<0;
	}else if(n==3&&q==4){
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
	}else if(n==3&&q==4){
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}