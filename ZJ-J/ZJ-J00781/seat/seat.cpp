#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
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
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int now_n=1,now_m=1;
	bool z=true;	
	for(int i=1;i<=n*m;i++){
	    if(a[i]==k){
	    	cout<<now_m<<" "<<now_n;
	    	break;
		}
		if(now_n==n&&z){
			now_m++;
			z=false;
		}else if(now_n==1&&!z){
			now_m++;
			z=true;
		}else{
			if(z){
				now_n++;
			}else{
				now_n--;
			}
		}
	}
	return 0;
}