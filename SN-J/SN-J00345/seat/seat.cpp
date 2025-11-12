//SN-J00345 张时墉 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c,r;
int a[10005];
int s[105][105];
int cnt;
int cmp(int r1,int r2){
	return r1>r2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(i%2==1){
				s[j][i]=a[cnt];
				if(a[cnt]==k){
					c=i;
					r=j;
				}
				
			}
			else{
				s[n-j+1][i]=a[cnt];
				if(a[cnt]==k){
					c=i;
					r=n-j+1;
				}
			
			}
			
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

