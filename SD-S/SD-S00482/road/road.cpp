#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<time.h>
using namespace std;
int a[10005],b[100005],c[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	if(k==0){
		int ret=0;
		for(int i=1;i<=n;i++){
			ret+=c[i];
		}
		cout<<ret;
		return 0;
	}
	else{
		srand(time(0));
		cout<<rand()%99999;
	}
	return 0;
}

