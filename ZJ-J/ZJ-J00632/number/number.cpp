#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long tong[15];
char a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int i=0;
	while(a[i]){
		int num;
		num=int(a[i]-'0');
		if(num>=0 && num<=9){
			tong[num]++;
		}
		i++;
	}
	for(int i=9;i>=0;i--){
		long long number=tong[i];
		while(number){
			cout<<i;
			
			
			number--;
		}
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
