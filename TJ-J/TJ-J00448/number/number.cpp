#include<bits/stdc++.h>
#include<string>
using namespace std;
int man[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string zhzs;
	string ppp;
	long long zhz=0;
	cin >> zhzs;
	for(int i=0;i<zhzs.length();i++){

			if(zhzs[i]-'0'>=0 && zhzs[i]-'0'<=9){
				int w=int(zhzs[i]-'0');
			
				man[zhz]=w;
			
				zhz++;
			}

	} 
	
	
	sort(man,man+zhz,cmp);

	for(int i=0;i<zhz;i++){
		cout << man[i];
	}
	return 0;
} 
