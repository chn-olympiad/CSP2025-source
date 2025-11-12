#include <bits/stdc++.h>
using namespace std;

const int N = 1e5

struct members(){
	int num,dpm1,dpm2,dpm3;
}mem[N];

int n,p;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> n;
	while(n-- > 0){
		cin >> p;
		for(int i = 1 ; i<=p ; i++){
			mem[i].num = i;
			cin >> mem[i].dpm1 >> mem[i].dpm2 >> mem[i].dpm3;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
