#include<iostream>
#include<string>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    int d = 0;
	char s[1000000] = {10};
    for(int i = 1;i < 100;i++){
    	cin >> s[i];
		if(s[i]=='0'){
    	    d++;
		}
	
	}
	char n[10000000] = {0};
	int x = 1;
	for(int i = 1;i < 100;i++){
		if(s[i]>='1'&&s[i]<='9'){
			n[x] = s[i];
			x++;
		}
	}
	int o[10000000] = {0};
	int y = 1;
	for(int i = 1;i < 100;i++){
		if(n[i]=='1'){
			n[y] = 1;
			y++;
		}
		if(n[i]=='2'){
			n[y] = 2;
			y++;
		}
		if(n[i]=='3'){
			n[y] = 3;
			y++;
		}
		if(n[i]=='4'){
			n[y] = 4;
			y++;
		}
		if(n[i]=='5'){
			n[y] = 5;
			y++;
		}
		if(n[i]=='6'){
			n[y] = 6;
			y++;
		}
		if(n[i]=='7'){
			n[y] = 7;
			y++;
		}
		if(n[i]=='8'){
			n[y] = 8;
			y++;
		}
		if(n[i]=='9'){
			n[y] = 9;
			y++;
		}
			
	}
	for(int i = 1;i < 100;i++){
		for(int j = i+1;j < 100;j++){
			if(o[i]<o[j]){
				swap(o[i],o[j]);
			}
		}
	}
	for(int i = 1;i < 100;i++){
		if(o[i]>0){
			cout << o[i];
		}
	}
	for(int i = 1;i <= d;i++){
		cout << 0;
	}
	
	return 0;
}
