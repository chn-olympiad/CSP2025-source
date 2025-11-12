#include<bits/stdc++.h>
using namespace std;
int n,m,num[150],r,cnt[105],x=1;
int a[12][12],t[10],ans[12][12];
bool flag;
bool cmp(int a,int b) {
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
	}
	r=num[1];
	sort(num+1,num+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(num[i]==r){
			r=i;
		}
	}
	for(int i=1;i<=n;i++){
		flag=1;
		for(int j=1;j<=m;j++){
			t[j]=x;
			x++;
		}
		for(int j=1;j<=m;j++){
			if(i%2==1&&flag){
				reverse(t+1,t+m+1);
				flag=0;
				a[i][j]=t[j];
			}
			else a[i][j]=t[j];
		}
	}
	int q=1,w=1;
	for(int i=n;i>=1;i--,q++){
		w=1;
		for(int j=1;j<=m;j++,w++){
			ans[q][w]=a[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==r){
				cout<<j<<" "<<i<<endl;
			}
		}
	}
	return 0;
}
