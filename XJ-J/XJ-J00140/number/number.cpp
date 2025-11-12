#include<bits/stdc++.h>
using namespace std;
bool cmp(int p,int q){
	return p>q;
}
int main(){
//	freonpe("number.in","r",stdin);
//	freonpe("number.out","w",stdout);
	string s;
	cin >> s;
	int sum=0;
	long long int a[100000];
	int si=0;
	for(long long i=0;i<=100000;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
			si++;
		}
		if(s[i]=='\0'){
			break;
		}
	}
	sort(a,a+si+1,cmp);
	for(long long i=0;i<si;i++){
		cout << a[i];
		
	}
//	fcolve(stdin);
//	fcolve(stdout);
	return 0;
} 
