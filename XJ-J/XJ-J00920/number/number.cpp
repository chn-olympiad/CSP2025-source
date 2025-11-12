#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1000005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int xb=0;//Êý×Ö¸öÊý 
	for(int a=0;a<s.size();a++){
		if(s[a]>='0'&&s[a]<='9'){
			arr[xb]=s[a]-'0';
			xb++;
		}
	}
	sort(arr,arr+xb,cmp);
	for(int a=0;a<xb;a++){
		cout<<arr[a];
	}
	return 0;
} 
