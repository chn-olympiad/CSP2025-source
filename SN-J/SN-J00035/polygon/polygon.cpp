//何乐怡 SN-J00035 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ret=0;
	int maxn=0;
	if(n==3){
		for(int i=1;i<=n;i++){
			ret+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(ret>maxn*2){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		} 
	}
	sort(a,a+n+1);
	if(n==4){
		int x=a[1]+a[2]+a[3];
		int y=a[1]+a[2]+a[4];
		int z=a[1]+a[3]+a[4];
		int b=a[2]+a[3]+a[4];
		if(x>a[3]*2)ret++;
		if(y>a[4]*2)ret++;
		if(z>a[4]*2)ret++;
		if(b>a[4]*2)ret++;
		cout<<ret;
		return 0;
	}
	if(n==5){
		int x=a[1]+a[2]+a[3];
		int y=a[1]+a[2]+a[4];
		int z=a[1]+a[2]+a[5];
		int b=a[1]+a[4]+a[3];
		int c=a[1]+a[3]+a[5];
		int d=a[1]+a[4]+a[5];
		int e=a[2]+a[3]+a[4];
		int f=a[2]+a[3]+a[5];
		int g=a[2]+a[4]+a[5];
		int h=a[3]+a[4]+a[5];
		if(x>a[3]*2)ret++;
		if(y>a[4]*2)ret++;
		if(z>a[5]*2)ret++;
		if(b>a[4]*2)ret++;
		if(c>a[5]*2)ret++;
		if(d>a[5]*2)ret++;
		if(e>a[4]*2)ret++;
		if(f>a[5]*2)ret++;
		if(g>a[5]*2)ret++;
		if(h>a[5]*2)ret++;
		cout<<ret;
	}
	return 0;
}
