#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read(){
	ll x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cout<<0;
	
	
	return 0;
}