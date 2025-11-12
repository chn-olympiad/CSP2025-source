#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long two[100005];
long long js=1;
bool flag[100005];
string qz[100005];
void zh(int x){
	if(x<2){
		two[js]=x;
	}
	long long jc=1; 
	while(x!=0){
		two[js]+=(x%2)*jc;
		x/=2;
		jc*=10;
	}
}
string ans;
void wyh(long long x,long long y){
	while(min(x,y)){
		if(x%10==y%10){
			ans+='1';
		}else{
			ans+='0';
		}
	}
	reverse(ans.begin(),ans.end());
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	string tk;
	while(k!=0){
		tk+=(k%2+'0');
		k/=2;
	}
	reverse(tk.begin(),tk.end());
	for(int i=1;i<=n;i++){
		flag[i]=true;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zh(a[i]);
		js++;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(k==a[i]&&flag[i]){
			sum++;
			flag[i]==false;
		}
	}
	long long m=1;
//	for(int i=1;i<=n;i++){
//		if(flag[i]){
//			for(int j=i;j<=n;j++){
//				wyh(two[j],two[j+1]);
//				if(ans==tk){
//					flag[j]=false;
//					flag[j+1]=false;
//					sum++;
//				}
//				if(flag[i]!=true){
//					break;
//				}
//				m++;
//				ans="0";
//			}
//		}
//	}
	cout<<sum;
	return 0;
}
