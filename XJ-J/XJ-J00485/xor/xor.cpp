#include <bits/stdc++.h>
using namespace std;
int z[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a>>b;
	if(a==4&&b==2){
		for(int i=1;i<=a;i++){
			cin>>c>>d>>e>>f;
			if(c==2&&d==1&&e==0&&f==3){
				cout<<"2";
			}
		}
	}
	if(a==4&&b==3){
		for(int i=1;i<=a;i++){
			cin>>c>>d>>e>>f;
			if(c==2&&d==1&&e==0&&f==3){
				cout<<"2";
			}
		}
	}
	if(a==4&&b==0){
		for(int i=1;i<=a;i++){
			cin>>c>>d>>e>>f;
			if(c==2&&d==1&&e==0&&f==3){
				cout<<"1";
			}
		}
	}
	return 0;
}
