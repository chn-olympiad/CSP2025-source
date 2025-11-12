#include<iostream>
using namespace std;
int main(){
	freopen("club.cpp","r",stdin);
	freopen("club.cpp","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		int a,b,c;
		int a1,b1,c1;
		for(int i=1;i<=m;i++){
			cin>>a>>b>>c;
			if(max(a,b,c)==a){
				a1+=a;
			}else if(max(a,b,c)==b){
				b1+=b;
			}else if(max(a,b,c)==c){
				c1+=c;
			}
		}
		int cnt=a1+b1+c1;
		cout<<cnt;
		cout<<endl;
	}
	return 0;
}
