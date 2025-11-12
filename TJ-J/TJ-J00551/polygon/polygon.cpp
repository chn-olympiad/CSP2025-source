#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r","std.in");
	freopen("polygon.out","w","std.out");
	long long a;
	cin>>a;
	srand(time(0));
	if(a<10) {
		for(int s=0;;){
			s=rand(%10);
			if(s>=5){
				cout<<s;
				return 0;
			}
		}
	}
	if(a>10) cout<<(rand()/1000);
	return 0;
}
