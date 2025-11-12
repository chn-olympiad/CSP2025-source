#include<bits/stdc++.h>
using namespace std;

freopen("D:\SN-J00343\number\number.in","r",stdin);
freopen("D:\SN-J00343\number\number.out","w",stdout);

long long cnt=0;
int a[100] ,b[100] ,maxn=0;
bool flag;
char s;

int main(){
 	for (int i=0;i<100;i++){
 		cin >> s;
		if (int(s)<=9 and int(s)>=0){
			a[cnt] = s;
			cnt += 1;
		}
	}
	
	while (true){
		int i=0;
		flag = false;
		for (int j=0;j<100;j++){
			if (a[j] > maxn and a[j]!=-1){
				maxn = a[j];
				a[j] = -1;
				flag = true;
			}
		}
		if(flag = true){
			b[i] = maxn;
		}else{
			break;
		}
		i++;
	}
	
	for (int i=0;i<100;i++){
		if(b[i] != -1){
			printf("%s",b[i]);
		}
	}
	
	return 0;
}
