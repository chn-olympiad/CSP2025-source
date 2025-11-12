#include<bits/stdc++.h>
using namespace std;
long long arr[100005];
int cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=1,js=0,ts=0;
	long long l=a.size();
	for(long long i=0;i<l;i++){
		if(a[i]>='a'){
			continue;
		}else{
			arr[i]=int(a[i]-'0');
			ts++;
		}
	}
	sort(arr,arr+l,cmp);
	for(long long i=l-ts;i<l;i++){
		js+=arr[i]*b;
		b*=10;
	}
	cout<<js;
	return 0;
}
