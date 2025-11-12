#include <bits/stdc++.h>
using namespace std;
int aa[100009];	int num=0;
bool cmp(int a,int b){

	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	getline(cin,a);

	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			aa[num++]=a[i]-48;
		
		}
	}num--;
	sort(aa,aa+num+1,cmp);
	
	for(int i=0;i<=num;i++){
	
		cout<<aa[i];
	}
	
	return 0;
} 
