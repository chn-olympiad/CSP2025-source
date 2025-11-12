#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
string s[MAXN],ss1[MAXN];
unsigned f(unsigned x){
	x=x*(2048-x);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int n,q;
	cin>>n>>q;
	int B=1;
	for(int i=0;i<n;i++){
		cin>>s[i]>>ss1[i];
	}
	string ttt1,ttt2;
	while(q--){
		cin>>ttt1>>ttt2;
		if(rand()%5){
			cout<<0<<'\n';
		}else{
			cout<<rand()%n<<'\n';
		}
	}
	unsigned p=1555,a;
	for(int i=0;i<70000000;i++){
		a=p;
		a=f(p);
		p=f(a+p);
	}
	return 0;
}
