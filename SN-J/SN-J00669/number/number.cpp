//武岳桐 SN-J00669 西安建筑科技大学附属中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a[1000005], qq = 0, ww = 0, ee = 0, rr = 0, tt = 0, yy = 0, uu = 0, ii = 0, oo = 0, pp = 0;
	scanf("%s", a);
	long long s = strlen(a);
	for(int i = 0;i < s;i++){
		if(a[i] == '1') qq++;
		if(a[i] == '2') ww++;
		if(a[i] == '3') ee++;
		if(a[i] == '4') rr++;
		if(a[i] == '5') tt++;
		if(a[i] == '6') yy++;
		if(a[i] == '7') uu++;
		if(a[i] == '8') ii++;
		if(a[i] == '9') oo++;
		if(a[i] == '0') pp++;
	}
	while(oo > 0){
		cout << "9";
		oo--;
	}
	while(ii > 0){
		cout << "8";
		ii--;
	}
	while(uu > 0){
		cout << "7";
		uu--;
	}
	while(yy > 0){
		cout << "6";
		yy--;
	}
	while(tt > 0){
		cout << "5";
		tt--;
	}
	while(rr > 0){
		cout << "4";
		rr--;
	}
	while(ee > 0){
		cout << "3";
		ee--;
	}
	while(ww > 0){
		cout << "2";
		ww--;
	}
	while(qq > 0){
		cout << "1";
		qq--;
	}
	while(pp > 0){
		cout << "0";
		pp--;
	}
	return 0;
}
