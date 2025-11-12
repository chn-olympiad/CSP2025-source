#include <bits/stdc++.h> 
using namespace std;
struct hg{
	int a;
	int b;
	int c;
};
bool cmp1(hg x,hg y){
	if(x.a>y.a){
		return true;
	}else{
		return false;
	}
}
bool cmp1(hg x,hg y){
	if(x.a>y.a){
		return true;
	}else{
		return false;
	}
}
bool cmp1(hg x,hg y){
	if(x.a>y.a){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int m;
		hg v[m];
		for(int i=0;i<3;i++)
			cin>>v[i].a>>v[i].b>>v[i].c;	
		sort(v,v+m,cmp1);
		for(int i=0;i<3;i++){
			for(int i=0;i<m;i++){
				
			}
		}
	}
	
	return 0;
}

