#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int arr[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int xb=0;
	for(int a=0;a<s.size();a++){
		if(s[a]>='0'&&s[a]<='9'){
			arr[a]=s[a]-'0';
			xb++;
		}
	}
	sort(arr,arr+xb,cmp);
	for(int a=0;a<xb;a++){
		cout<<arr[a];
	}
	return 0;
}
