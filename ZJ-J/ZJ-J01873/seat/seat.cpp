#include<bits/stdc++.h>

using namespace std;
int n,m,a[105],k,tot,x,c,r;
bool cmp(int i,int j){return i>j;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;tot=n*m;
	for(int i=1;i<=tot;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++) if(a[i]==k){x=i;break;}
	if(x%n==0) c=x/n;
	else c=x/n+1;
	if(c%2==1){
		if(x%n==0) r=n;
		else r=x%n;
	}else{
		if(x%n==0) r=1;
		else r=n-x%n+1;
	}cout<<c<<' '<<r;
	return 0;
}/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

100 87 86 73 72
 99 88 85 74 71
 98 89 84 75 70
 97 90 83 76 69
 96 91 82 77 68
 95 92 81 78 67
 94 93 80 79 66
 
7 5
69 99 98 97 96 95 80 94 92 91 90 89 88 66 87 85 76 83 100 81 84 93 78 77 79 75 74 86 73 71 70 72 68 67 82 
*/
