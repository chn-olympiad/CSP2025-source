#include <bits/stdc++.h>
using namespace std;
int n=0;
int num[20];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			num[1]++;
		}
		if(a[i]=='1'){
			num[2]++;
		}
		if(a[i]=='2'){
			num[3]++;
		}
		if(a[i]=='3'){
			num[4]++;
		}
		if(a[i]=='4'){
			num[5]++;
		}
		if(a[i]=='5'){
			num[6]++;
		}
		if(a[i]=='6'){
			num[7]++;
		}
		if(a[i]=='7'){
			num[8]++;
		}
		if(a[i]=='8'){
			num[9]++;
		}
		if(a[i]=='9'){
			num[10]++;
		}
	}
	for(int i=10;i>=1;i--){
		if(num[i]>0){
			for(int j=1;j<=num[i];j++){
				cout<<i-1;
			}
		}
	}
	
	return 0;
}
