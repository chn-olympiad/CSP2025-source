#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10001][4];
	int b1[10001];
	int yyy[100001];
	int yy[100001];
	int n;
	int u1,u2;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j==1){
				b1[i]=a[i][j];
				
			}
			if(j==1){
				u1=u1+a[i][j];
			}
			if(j==2){
				u2=u2+a[i][j];
			}
		
		}
	}
	u1=u1/n;
	u2=u2/n;
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0||a[i][3]!=0){
			break;
		}
		else{
			sort(b1+1,b1+1+n);
			int c=0;
			cout<<b1[1]<<"      ";
			for(int i=n;i>n/2;i++){
				c=c+b1[i];
				
			}
			cout<<c;
			return 0;
		}
	}
	int c1=0;
	int t=max(u1,u2);
	if(t==u1){
		t=1;
	}
	else{
		t=2;
	}

	if(t==1){
		for(int i=1;i<=n;i++){
			yyy[i]=a[i][1];
			yy[i]=i;
		}
		
		for(int y=1;y<=n;y++){
			for(int o=1;o<=y;o++){
				int hg=0;
				if(yyy[y]<yyy[o]){
					hg=yy[y];
					yy[y]=yy[o];
					yy[o]=hg;
					
					
				}
			}
				
		}
		for(int i=1;i<=n/2;i++){
			c1=c1+a[yy[i]][1];
		}
		for(int i=1;i<=n;i++){
			if(i!=yy[i]){
				c1=c1+a[i][2];
			}
			
		}
		cout<<c1;
		
		
		
	}else{
		for(int i=1;i<=n;i++){
			yyy[i]=a[i][1];
			yy[i]=i;
		}
		
		for(int y=1;y<=n;y++){
			for(int o=1;o<=y;o++){
				int hg=0;
				if(yyy[y]<yyy[o]){
					hg=yy[y];
					yy[y]=yy[o];
					yy[o]=hg;
					
					
				}
			}
			
		}
		for(int i=1;i<=n/2;i++){
			c1=c1+a[yy[i]][1];
		}
		for(int i=1;i<=n;i++){
			if(i!=yy[i]){
				c1=c1+a[i][2];
			}
			
		}
		cout<<c1;
	}
	
	
	
	
	
	
	
}