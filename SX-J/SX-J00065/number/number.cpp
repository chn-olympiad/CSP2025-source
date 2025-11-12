#include<bits/stdc++.h>
using namespace std;
int num[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	int n=x.size();
	int cnt=0;
	int z=0;
	for(int i=0;i<n;i++){
		if(x[i]>='0' && x[i]<='9'){
			num[i]=x[i]-48;
			z++;
		}else{
			cnt++;
		}
	}
	sort(num,num+n,cmp);

	for(int i=0;i<n-cnt;i++){
			cout<<num[i];

	}//cout<<cnt;
	return 0;
}