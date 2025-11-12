#include <bits/stdc++.h>
using namespace std;
int arr[10000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	int len=s.size();
	int x=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[++x]=s[i]-'0';
		}
	}
	sort(arr+1,arr+1+x,cmp);
	for(int i=1;i<=x;i++){
		cout<<arr[i];
	}
	return 0;
} 
