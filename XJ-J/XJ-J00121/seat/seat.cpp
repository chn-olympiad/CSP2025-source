#include<bits/stdc++.h>
using namespace std;
int a[10][10],b[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,len,r;
	memset(a,0,sizeof(a));
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>b[i];
	}r=b[1];
	sort(b+1,b+len+1);
	int x=1,y=1;
	for(int i=len;i>0;i--){
		if(b[i]==r){
			cout<<x<<' '<<y;
			}
			a[y][x]=b[i];
			if((len-i+1)%n==0){
				x++;
			}else{
				if(x%2==0){
					y--;
				}else if(x%2==1){
					y++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
