#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,t,s,w,bao,flag,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	for(i=1;i<=n*m;i++)if(a[i]>x)s++;
	bao=s+1;
	t=1;w=1;flag=1;
	while(--bao){
		if(flag==1)
			if(t<n)t+=flag;
			else w++,flag=-flag;
		else 
			if(t>1)t+=flag;
			else w++,flag=-flag;
	}
	cout<<w<<" "<<t;
	return 0;
}
