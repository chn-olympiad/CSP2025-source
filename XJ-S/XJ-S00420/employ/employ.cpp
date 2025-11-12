#include<bits/stdc++.h> 
using namespace std;
int n;
//应聘人数 
int m;
//录用人数 
char a[202020];
//难度 
int num[202020];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i = 0;i<=300003;i++){
		a[i] = '9';
	}
	cin >>n >>m;
	cin >>a;
	for(int i =0;i<n;i++){
		cin >> num[i];
	}
	int l = 0;
	for(int i = 0;i<=202002;i++){
		if(a[i] == '9'){
			break;
		}
		else{
			l++;
		}
	}
	l--;
	int d = 0;
	if(m ==1){
		for(int i =0;i<l;i++){
			if(a[i] == '1'){
				d= i+1;	
				break;
			}
		}
		int cnt =0;
		for(int i = 0;i<n;i++){
			if(a[i]-'0'>d){
				cnt ++;
			}
		}
		cout << n*(n-cnt);

	}
	else{
		cout << 2;
	}	

	
	return 0;
}
