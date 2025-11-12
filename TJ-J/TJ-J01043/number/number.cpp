#include<bits/stdc++.h>
using namespace std;
string xz;
long long nnm=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>xz;
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='9'){
			cout<<"9";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='8'){
			cout<<"8";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='7'){
			cout<<"7";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='6'){
			cout<<"6";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='5'){
			cout<<"5";
		}
	}
	
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='4'){
			cout<<"4";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='3'){
			cout<<"3";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='2'){
			cout<<"2";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='1'){
			cout<<"1";
		}
	}
	for(long long j=0;j<=xz.length()-1;j++){
		if(xz[j]=='0'){
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
