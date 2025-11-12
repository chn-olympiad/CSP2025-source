//原梓轩 440514201308033019 陕西西安 锦园中学 
#include<bits/stdc++.h>
using namespace std;
struct kaosheng{
	int a,b,c;
}m[114514];
int t,n;
bool cmp1(kaosheng x,kaosheng y){
	return x.b>y.b;
}
bool cmp2(kaosheng x,kaosheng y){
	return x.b>y.b;
}
bool cmp3(kaosheng x,kaosheng y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int max_=-1,jg=-1;
		for(int i=0;i<n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		if(m[0].a>=m[0].b&&m[0].b>=m[0].c&&m[1].b>=m[1].a&&m[1].b>=m[1].c||m[0].a>=m[0].b&&m[0].b>=m[0].c&&m[1].c>=m[1].a&&m[1].c>=m[1].b||m[0].b>=m[0].a&&m[0].b>=m[0].c&&m[1].a>=m[1].b&&m[1].b>=m[1].c||m[0].b>=m[0].a&&m[0].b>=m[0].c&&m[1].c>=m[1].a&&m[1].c>=m[1].a||m[0].c>=m[0].b&&m[0].b>=m[0].a&&m[1].a>=m[1].b&&m[1].b>=m[1].c||m[0].b>=m[0].a&&m[0].b>=m[0].c&&m[1].c>=m[1].b&&m[1].b>=m[1].a){
			if(m[0].a>=m[0].b&&m[0].b>=m[0].c&&m[1].b>=m[1].a&&m[1].b>=m[1].c){
				cout<<"";
			}
			else if(m[0].a>=m[0].b&&m[0].b>=m[0].c&&m[1].c>=m[1].a&&m[1].c>=m[1].b){
				
			}
			else if(m[0].b>=m[0].a&&m[0].b>=m[0].c&&m[1].a>=m[1].b&&m[1].b>=m[1].c){
				
			}
			else if(m[0].b>=m[0].a&&m[0].b>=m[0].c&&m[1].c>=m[1].a&&m[1].c>=m[1].a){
				
			}
			else if(m[0].c>=m[0].b&&m[0].b>=m[0].a&&m[1].a>=m[1].b&&m[1].b>=m[1].c){
				
			}
			else{
				
			}
		}
	}
	return 0;
} 
