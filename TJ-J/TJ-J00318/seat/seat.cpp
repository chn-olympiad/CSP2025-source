#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,s=0,t=0,x=1,y=1,f=0;
long long a[100]={0},b[100][100]={-1},nx[3]={1,0,-1},ny[3]={0,1,0};
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	t=n*m;
	sort(a+1,a+t+1);
	t--;
	b[1][1]=a[t+1];
	while(t>0){
		if(x+nx[f]<n+1&&x+nx[f]>0&&y+ny[f]<m+1&&y+ny[f]>0){
			x+=nx[f];
			y+=ny[f];
			b[x][y]=a[t];
			t--;
			if(f==1){
				f++;
			}
			else if(f==2){
				f=0;
			}
		}
		else{
			f++;
			if(f==3){
				f=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==s){
				cout<<j<<","<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
