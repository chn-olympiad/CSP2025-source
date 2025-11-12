#include<bits/stdc++.h>
using namespace std;

struct node{
	long long x;
	long long y;	
}a[1005];
bool cmp(node a,node b){
	return a.x>b.x;
}
long long n,m,i,x,y,l,r;
bool f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,cmp);
	f=1;
	x=1;
	y=1;
	for(i=1;i<=n*m;i++){
//		cout<<a[i].y<<" ";
		if(a[i].y==1){
			l=x;
			r=y;
			break;
		}
		else{
			if(y==1&&f==0){
				f=1;
				x++;
			}
			else{
				if(y==n&&f==1){
					f=0;
					x++;
				}
				else{
					if(f==0){
						y--;
					}
					else{
						y++;
					}
				}
			}
		}
	}
//	cout<<"\n";
	cout<<l<<" "<<r;
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/