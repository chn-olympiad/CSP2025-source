#include<bits/stdc++.h>
using namespace std;
int grade[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i];
	}
	int r=grade[1];
	sort(grade+1,grade+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(grade[i]==r){
			int x,y;
			if(i%n==0){
				if(i/n%2==1){
					x=i/n;
					y=i%n;
					if(y==0){
						y+=n;
					}
				}else{
					x=i/n;
					y=n-(i%n)+1;
					if(y==0){
						y+=n;
					}
				}
			}else{
				if((i/n+1)%2==1){
					x=i/n+1;
					y=i%n;
					if(y==0){
						y+=n;
					}
				}else{
					x=i/n+1;
					y=n-(i%n)+1;
					if(y==0){
						y+=n;
					}
				}
			}
			cout<<x<<" "<<y;
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
