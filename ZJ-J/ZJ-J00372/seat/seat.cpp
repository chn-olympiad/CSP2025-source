#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int h,l,a,b,c,mc,w;
vector<int>e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&h,&l,&a);
	e.push_back(a);
	for(int i=0;i<h*l-1;i++){
		scanf("%d",&b);
		e.push_back(b);
	}
	sort(e.begin(),e.end());
	for(int i=0;i<e.size();i++){
		if(a==e[i]){
			mc=h*l-i;
			break;
		}
	}
	printf("%d ",(mc-1)/h+1);
	w=(mc-1)%(h*2)+1;
	if(w<=h)printf("%d",w);
	else printf("%d",h-(w-h)+1);
	return 0;
}
