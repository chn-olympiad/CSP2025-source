#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w", stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||n==2){
		cout<<0<<endl;
	}
	else if(n==3){
		int maxn=max(a[1], a[2]);
		maxn=max(maxn, a[3]);
		if(a[1]+a[2]+a[3]>maxn){
			cnt++;
		}
		cout<<cnt;
	}
	else if(n==4){
		int maxn=max(a[1], a[2]);
		maxn=max(maxn, a[3]);
		maxn=max(maxn, a[4]);
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2], a[3]))){
			cnt++;
		}
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2], a[4]))){
			cnt++;
		}
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3], a[4]))){
			cnt++;
		}
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3], a[4]))){
			cnt++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3], a[4])))){
			cnt++;
		}
		cout<<cnt;
	}
	else if(n==5){
		int maxn=max(a[1], a[2]);
		maxn=max(maxn, a[3]);
		maxn=max(maxn, a[4]);
		maxn=max(maxn, a[5]);
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2], a[3]))){
			cnt++;
		}
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2], a[4]))){
			cnt++;
		}
		if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2], a[5]))){
			cnt++;
		}
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3], a[4]))){
			cnt++;
		}
		if(a[1]+a[3]+a[5]>2*max(a[1],max(a[3], a[5]))){
			cnt++;
		}
		if(a[1]+a[4]+a[5]>2*max(a[1],max(a[4], a[5]))){
			cnt++;
		}
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3], a[4]))){
			cnt++;
		}
		if(a[2]+a[3]+a[5]>2*max(a[2],max(a[3], a[5]))){
			cnt++;
		}
		if(a[2]+a[4]+a[5]>2*max(a[2],max(a[4], a[5]))){
			cnt++;
		}
		if(a[3]+a[4]+a[5]>2*max(a[3],max(a[4], a[5]))){
			cnt++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3], a[4])))){
			cnt++;
		}
		if(a[1]+a[2]+a[3]+a[5]>2*max(a[1],max(a[2],max(a[3], a[5])))){
			cnt++;
		}
		if(a[1]+a[2]+a[4]+a[5]>2*max(a[1],max(a[2],max(a[4], a[5])))){
			cnt++;
		}
		if(a[1]+a[3]+a[4]+a[5]>2*max(a[1],max(a[3],max(a[4], a[5])))){
			cnt++;
		}
		if(a[2]+a[3]+a[4]+a[5]>2*max(a[2],max(a[3],max(a[4], a[5])))){
			cnt++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(a[1], max(a[2],max(a[3],max(a[4], a[5]))))){
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
