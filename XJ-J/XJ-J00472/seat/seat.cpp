#include <bits/stdc++.h>

using namespace std;
int num[100010];
int num1[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s = 0,cnt = 0;
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> num[i];
		num1[i] = i;
	}
	int kong = 0,kong1 = 0;
	for(int i = 1;i<=n*m;i++){
		for(int j = i+1;j<=n*m;j++){
			if(num[i] < num[j]){
				kong = num[j];
				num[j] = num[i]; 
				num[i] = kong;
				//·ÖÊýÅÅÐò 
				kong = num1[j];
				num1[j] = num1[i];
				num1[i] = kong; 
				//±àºÅÅÅÐò 
			}
		}
	}
	int n1 = 0,m1=0;
	for(int i = 1;i<=n*m;i++){
		if(num1[i] == 1){
			n1 = cnt/n + 1;
			m1 = cnt%n + 1;
			cout << n1 << " "<< m1;
		}else{
			cnt++;
		}
	}
	return 0; 
} 
