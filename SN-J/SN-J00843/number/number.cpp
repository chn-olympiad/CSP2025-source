#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int k=0;
	int len=s.size();
	long long a[len+5];
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	} 
	for(int i=0;i<k;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<k;i++){
		cout << a[i];
	} 
	return 0;
} 
