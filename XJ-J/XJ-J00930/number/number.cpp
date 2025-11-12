#include <bits/stdc++.h>
using namespace std;
int num[1000005],p = 0;
string a;
void tonumber(char x){
	if(x == '0'){
		num[p] = 0;
		p++;
	}
	else if(x == '1'){
		num[p] = 1; 
		p++;
	}
	else if(x == '2'){
		num[p] = 2;
		p++;
	}
	else if(x == '3'){
		num[p] = 3;
		p++;
	}
	else if(x == '4'){
		num[p] = 4; 
		p++;
	}
	else if(x == '5'){
		num[p] = 5;
		p++;
	}
	else if(x == '6'){
		num[p] = 6;
		p++;
	}
	else if(x == '7'){
		num[p] = 7; 
		p++;
	}
	else if(x == '8'){
		num[p] = 8;
		p++;
	}
	else if(x == '9'){
		num[p] = 9;
		p++;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i = 0;i<a.size();i++){
		tonumber(a[i]);
	}
	sort(num,num+p);
	for (int i = p-1;i>=0;i--){
		cout << num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//CCF orz
