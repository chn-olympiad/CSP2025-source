#include<bits/stdc++.h>
using namespace std;

int h,l,lie,hang;
int mark[102],my;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&h,&l);
	for(int i=0;i<h*l;i++){
		scanf("%d",&mark[i]);		
		if(!i)
			my=mark[i];		
	}
	
	sort(mark,mark+l*h);
	
	for(int i=0,k=h*l-1;i<h*l;i++,k--){
		if(my==mark[k]){
			my=i+1;
			break;
		}
	}
	
	lie=my/h;
	if(my%h)
		lie++;
	
	if(lie%2){
		hang=my%h;
		if(my==h)
			hang=h;
	}else{
		hang=h-(my%h)+1;
		if(my==h)
			hang=1;
	}
	
	printf("%d %d",lie,hang);	
	
	return 0;
}
