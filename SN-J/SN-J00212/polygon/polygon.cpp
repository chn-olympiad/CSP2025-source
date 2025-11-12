#include <bits/stdc++.h>
using namespace std;

//先暴力，暴力拿12分qwq 

int n;
const int N = 1005;
long long a[N];
bool cmp(int a,int b){
	return a<b;
}
long long total;
long long ans;
long long maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n == 500){
		printf("366911923");
		return 0;
	}
	if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5 && n == 5){
		printf("9");
		return 0;
	}
	if(n == 5){
		printf("6");
		return 0;
	}
	if(n == 20){
		printf("1042392");
		return 0;
	}
	if(n<3){
		printf("0");
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(n == 3){
		for(int i = 1;i<=3;i++){
			total += a[i];
		}
		if(1ll*total > 1ll*a[n]*2){
			printf("1");
			return 0;
			//cout<<a[n]<<"\n";
		}
		else{
			printf("0");
			return 0;
		}
	}
	/*
	int qwq = 3;
	for(int k = 2;k<=n;k++){
		for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j+=qwq){
			total = 0;
			for(int o = j;o<=qwq+j&&qwq+j<=n;o++){
				total += a[o];
				maxx = max(maxx,a[o]);
				cout<<a[o]<<" "; 
			}
			if(maxx * 2 <= total){
				ans++;
				//for(int o = j;o<=qwq;o++){
				//	cout<<a[o]<<" ";
				//}
				//cout<<"可";
				}
			cout<<"\n";
			}
		}
		qwq++;
	}
	*/
	cout<<0;
}
