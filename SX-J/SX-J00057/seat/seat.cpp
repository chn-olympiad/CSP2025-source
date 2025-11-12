#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a+1,a+n*m,cmp);
	int h=1,l=1;
	for(int i=1;i<n*m;i++){
		if(a[i]>k){
			if(l%2!=0&&h!=n) h++;
			else if(l%2!=0&&h==n) l++;
			else if(l%2==0&&h!=1) h--;
			else if(l%2==0&&h==1) l++;
		}
		else if(a[i]<k){
			cout<<l<<" "<<h;
			break;
		}
	}
	return 0;
}
/*
2 2
99 100 97 98
*/