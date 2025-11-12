#include<bits/stdc++.h>
using namespace std;
int goal,id,n,m,x,y;
int a[13][13],sc[130];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	/**/freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];	
		if(i==1)	goal=sc[i];
	}
	sort(sc+1,sc+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sc[i]==goal){
			id=i;
			break;
		}
	}
	//-----
	x=(id-1)/n+1;
	if(x%2==0)	y=n-(id-(x-1)*n)+1;
	else	y=id-(x-1)*n;
	cout<<x<<' '<<y;
	return 0;
}
