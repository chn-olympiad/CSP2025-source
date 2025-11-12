#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
	string b,c,d,e,f,g,h,i,j,k;
	for(int s = 0;s <= a.size();s++){
		if(a[s] == '9')b += '9';
		if(a[s] == '8')c += '8';
		if(a[s] == '7')d += '7';
		if(a[s] == '6')e += '6';
		if(a[s] == '5')f += '5';
		if(a[s] == '4')g += '4';
		if(a[s] == '3')h += '3';
		if(a[s] == '2')i += '2';
		if(a[s] == '1')j += '1';
		if(a[s] == '0')k += '0';
	}
	cout<<b+c+d+e+f+g+h+i+j+k;
	fclose(stdin);
    fclose(stdout);
    return 0;
}

