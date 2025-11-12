//白祖铭，SN-J00838，宝塔区第一中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[10011],op;
int t,l;
bool cmp(int liu,int sa){
	if(liu<=sa){
		return liu>=sa;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
	scanf("%d",&a[i]);
		if(i==1){
			op=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==op){
			if(i%n==0){
				if(i/n%2==0){
					l=1;
				}else{
					l=n;
				}
				t=i/n;
			}else{	
				t=i/n+1;
				if((i/n+1)%2==0){
					l=n-(i%n-1);
				}else{
					l=i%n;
				}
			}
		}
	}
	cout<<t<<" "<<l;	
	return 0;
}
