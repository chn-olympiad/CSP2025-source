//SN-j00690 涂智竣 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],s[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+1+n*m,cmp);
	int q=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=a[q];
				q++;
			}
		}else {
			for(int j=n;j>=1;j--){
				s[j][i]=a[q];
				q++;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==w){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
