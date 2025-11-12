#include<bits/stdc++.h>

using namespace std;

string a;
int n;
int num[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin >> a;
	a = a+'*';
	int i = 0, j = 1;
	do{
		if(a[i] <= '9' && a[i] >= '0'){
			num[j] = int(a[i]) - '0';
			j++;
		}
		i++;
	}while(a[i] != '*');
	
	
	sort(num+1, num+j+1);
	
	for(int x = j; x > 1;x--){
			printf("%d", num[x]);
		}
			
	return 0;
}

