#include<bits/stdc++.h>
using namespace std;
int num[100007];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int index = 0;
	for(int i = 0;i<a.size();i++){
		if(a[i]>=48 && a[i]<=57){
			num[index] = a[i]-48;
			index++;
		}
	}
	sort(num,num+index,cmp);
	if(num[0] == 0){
		cout << 0;
		return 0;
	}
	for(int i = 0;i<index;i++){
		cout << num[i];
	}
	return 0;
}
