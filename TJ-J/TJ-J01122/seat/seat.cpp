#include<iostream>
#include<algorithm>
using namespace std;
int x,y,a1[110],a[110],ls,flag,xm,j,xxm,yxm;
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	ls=x*y;
	for(int i=1;i<=ls;i++){
		cin>>a1[i];
	}
	xm=a1[1];
	sort(a1+1,a1+ls+1);
	for(int i=ls,k=1;i>=1;k++,i--){
		a[k]=a1[i];
	}
	for(int i=1;i<=ls;i++){
		if(a[i]==xm){
			flag=i;
			break;
		}
	}
	if(flag%x==0){
		xxm=flag/x;
	}else{
		xxm=flag/x+1;	
	}
	if(xxm%2!=0){
		for(int i=(xxm-1)*x+1;i<=(xxm-1)*x+x;i++){
			j+=1;
			if(a[i]==xm){
				yxm=j;
				break;
			}
		}
		cout<<xxm<<" "<<yxm;
		return 0;
	}
	if(xxm%2==0){
		for(int i=(xxm-1)*x+1;i<=(xxm-1)*x+x;i++){
			j+=1;
			if(a[i]==xm){
				yxm=j;
				break;
			}
		}
		cout<<xxm<<" "<<x-yxm+1;
		return 0;	
	}
	
	fclose(stdin);
	fclose(stdout);
}
