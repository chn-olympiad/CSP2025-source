#include<bits/stdc++.h>
using namespace std;
int n,m,i,x,s,h,l;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n*m;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(i=1;i<=n*m;i++){
    	if(a[i]==x){
    		s=i;
    		break;
		}
	}
	if(s==1){
		cout<<"1 1";
		return 0;
	}
	h=1;
	l=1;
	for(i=2;i<=s;i++){
		if(l%2==1){
			if(h==n) l++;
			else h++;
		}
		else{
			if(h==1) l++;
			else h--;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}