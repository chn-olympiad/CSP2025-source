#include<iostream>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,zong,chenji[100],o,h;
	cin>>n>>m;
	zong=n*m;
	for(int i=0;i<zong;++i){
		cin>>chenji[i];
	}
	h=chenji[0];
	for(int i=0;i<100;++i){
		for(int j=0;j<100;++j){
			if(chenji[i]<chenji[i+1]){
				o=chenji[i];
				chenji[i]=chenji[i+1];
				chenji[i+1]=o;
			}
		}
	}
	for(int i=0;i<100;++i){
		if(chenji[i]==h) h=i;
}
	cout<<h/n<<h-(h/n);
	return 0;
}
