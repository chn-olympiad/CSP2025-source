#include<bits/stdc++.h>
using namespace std;
int a,b,w;
struct node{
	int x,y;
};
node n[110];
bool cmp(node aa,node bb){
	return aa.x>bb.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>n[i].x;
		n[i].y=i;
	}
	sort(n+0,n+a*b,cmp);
	for(int i=0;i<a*b;i++){
		if(!n[i].y){
			w=i;
			break;
		}
	}
	cout<<w/a+1<<' ';
	if((w/a)%2){
		cout<<a-w%a;
	}
	else{
		cout<<w%a+1;
	}
	return 0;
}
