#include<bits/stdc++.h>
using namespace std;
char a[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	int len = b.size();
	int j = 1;
	for(int i = 0;i<len;i++){
		if(b[i]<='9'&&b[i]>='0'){
			a[j] = b[i];
			j++;
		}
	}
	sort(a+1,a+j+1);
	for(int i = j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
