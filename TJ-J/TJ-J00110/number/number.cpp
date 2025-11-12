#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int sum[10];
int b=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a;
	cin>>a;
	
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			sum[b]=a[i]-48;
			b++;
		}
	}
	sort(sum,sum+b,cmp);
	for(int i=0;i<b;i++){
		cout<<sum[i];
	}
	return 0;
}
