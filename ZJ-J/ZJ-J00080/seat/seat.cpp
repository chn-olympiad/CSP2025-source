#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		r=a[1];
	}
	int i=1,j=1,cnt=1;
	bool flag=1;
	sort(a+1,a+n*m+1,cmp);
	while(a[cnt]!=r){
		
		if(j==m&&flag){
			i++;
			flag=0;
			cnt++;
			continue;
		}
		if(j==1&&!flag){
			i++;
			flag=1;
			cnt++;
			continue;
		}
		if(flag){
			++j;
			++cnt;
			continue;
		}else{
			--j;
			++cnt;
			continue;
		}
	}
	cout<<i<<" "<<j;
	return 0;
}
