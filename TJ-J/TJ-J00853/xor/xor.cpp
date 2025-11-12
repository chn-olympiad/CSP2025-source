#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],set_1[N];
void solve1(){cout<<n/2;}
void solve2(){
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				cnt++;
		cout<<cnt;
	}
	else{
		int cnt_0=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				cnt_0++;
		int len=0,cnt=0,t=false;
		for(int i=1;i<=n+1;i++){
			if(a[i]==1&&t==false){
				t=true;
				cnt++;
			}
			else if(a[i]==1&&t==true){
				cnt++;
			}
			else if(a[i]==0&&t==true){
				t=false;
				set_1[++len]=cnt;
				cnt=0;
			}
		}
		int cnt_1=0;
		for(int i=1;i<=len;i++)
			cnt_1+=(set_1[i]/2);
		cout<<cnt_0+cnt_1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool flag1=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag1=false;
			break;
		}
	}
	if(flag1&&k==0){
		solve1();
		return 0;
	}
	bool flag2=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0){
			flag1=false;
			break;
		}
	}
	if(flag2){
		solve2();
		return 0;
	}
	cout<<0;
	return 0;
}
