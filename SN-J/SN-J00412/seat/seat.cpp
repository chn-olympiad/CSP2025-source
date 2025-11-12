//准考证号:SN-J00412
//姓名:张轩祎
//学校:西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],ans[20][20];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cheng=a[1];
	sort(a+1,a+n*m+1,cmp);
	int seat=0;
	for(int i=1;i<=n;){
		for(int j=1;j<=m;j++){
			seat++;
			if(a[seat]!=cheng) ans[i][j]=a[seat];
			else{cout<<i<<" "<<j;return 0;}
		}
		i++;
		for(int j=m;j>=1;j--){
			seat++;
			if(a[seat]!=cheng) ans[i][j]=a[seat];
			else{cout<<i<<" "<<j;return 0;}
		}
		i++;
	}
	return 0;
}

