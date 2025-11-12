#include<bits/stdc++.h>
using namespace std;
int a=0,b,c,d,e,f,g;
char q[1111111];
int p[1111111];
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	int x=0;
	while(q[x]){
		if(q[x]<='9'&&q[x]>='0'){
			p[a]=q[x]-48;
			a++;
		}
		x++;
	}
	for(int y=0;y<a-1;y++){
		for(int z=y+1;z<a;z++){
			if(p[y]<p[z]){
				g=p[y];
				p[y]=p[z];
				p[z]=g;
			}
		}
	}
	for(int y=0;y<a;y++){
		cout<<p[y];
	}
	return 0;
}
