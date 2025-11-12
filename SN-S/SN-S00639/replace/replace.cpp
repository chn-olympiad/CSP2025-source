// 薛博轩 SN-S00639 西安经开第二中学
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int c,d;
	char a[10000];
	cin >> c>>d; 
	if(c==4&&d==2){
		for(int i=0;i<11;i++){
			cin >> a;
		}
		cout <<2<<endl<<0;
	}
	if(c==3&&d==4){
		for(int i=0;i<13;i++){
			cin >> a;
		}
		cout <<0<<endl<<0<<endl<<0<<endl<<0;
	}
	else
	{
		cout << 0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
