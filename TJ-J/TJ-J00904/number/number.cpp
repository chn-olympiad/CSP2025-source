#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
long long cnt,num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(long long i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[cnt]=a[i]-48;
			cnt++;
		}
	}
	sort(&num[0],&num[cnt],cmp);
	for(long long i=0;i<cnt;i++){
		cout<<num[i];
	}
	return 0;
} 
