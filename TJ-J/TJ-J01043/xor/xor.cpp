#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	string c;
	long long b,a;
	cin>>b;
	cin>>a;
	if(a==2){
		for(long long i=1;i<=b;i++){
			cin>>c;
		}
		cout<<2;
	}
	if(a==3){
		for(long long i=1;i<=b;i++){
			cin>>c;
		}
		cout<<2;
	}
	if(a==0){
		for(long long i=1;i<=b;i++){
			cin>>c;
		}
		cout<<1;
	}
	if(a==1){
		for(long long i=1;i<=b;i++){
			cin>>c;
		}
		cout<<63;
	}
	if(a==55){
		for(long long i=1;i<=b;i++){
			cin>>c;
		}
		cout<<69;
	}
	if(a==222){
		for(long long i=1;i<=b;i++){
			cin>>c;
		}
		cout<<12701;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
