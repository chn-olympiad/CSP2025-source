include <iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cin>>n;
	string s;
	string n;
	for (int i=0;i<=s.length()-1;i++){
		if(s.length(i)=="0","9"){
			n+=s.lenth(i);
		}
	}
	cin>>pin;
	for (int i=0;i<=n.length()-1;i++){
		if(n.length(i)<n.length(i-1)){
			pin+=n.length(i-1);
		}
	}
	return 0;
} 
