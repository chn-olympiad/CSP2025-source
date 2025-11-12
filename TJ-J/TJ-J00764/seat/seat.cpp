#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int v,p;
}a[110];
bool cmp(node a1,node a2){
	return a1.v>a2.v;
}
int main(){
//	freopen("seat","r",in);
//	freopen("seat","w",out); 
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].v;
		a[i].p=i;
	}
	sort(a,a+n*m,cmp);
	int i;
	for(i=0;i<n*m;i++){
		if(a[i].p==0){
			i++;
			break;
		}
	}
	int x=(i-1)/m+1,y;
	if(x%2==0){
		y=m-i%(m+1);
	}
	else{
		y=i%m;
		if(i%m==0){
			y=m;
		}
	}
	cout<<x<<" "<<y; 
//	freclose("seat",in);
//	freclose("seat",out);
	return 0;
}
