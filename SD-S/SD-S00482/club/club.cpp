#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<time.h>
using namespace std;
int a[1000005][3],flag[10000005];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int maxx=n/2;
		srand(time(NULL));
		for(int i=1;i<=n;i++){
			cout<<rand()<<endl;
		}
	}
	return 0;
}

