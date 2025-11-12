#include<bits/stdc++.h>
using namespace std;
int a[10051],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>b;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	int x=1,y=1;
	for(int i=n*m-1;i>0;i--){
		int c=0;
		if(b>a[i]){
			cout<<x<<' '<<y<<endl;
			break;
		}
		else{
			if(x%2!=0){
				if(y+1>m){
					x+=1;
					c=1;
				}
				else y+=1;
			}
			else if(x%2==0&&c==0){
				if(y-1<1) x+=1;
				else y-=1;
			}
		}
	}
	return 0;
}
