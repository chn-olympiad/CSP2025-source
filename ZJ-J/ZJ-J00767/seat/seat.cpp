#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[105];
bool cmp(int a,int b){return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x_score=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x_score=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=0,s=1,f=1;
	while(s<=n*m){
		y+=f;
		if(y==m+1 and f==1){
			f=-1;
			x++;
			y=m;
		}else if(y==0 and f==-1){
			f=1;
			x++;
			y=1;
		}
		if(a[s]==x_score){
			cout<<x<<" "<<y;
			break;
		}
		s++;
	}
//	cout<<s<<" "<<x<<" "<<y;
	return 0;
}
