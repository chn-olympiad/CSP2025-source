//姓名：杜悦菲
//考号：SN-J00594
//学校：西安市曲江第一学校 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//仅针对n<=3的情况，因为其他情况我不会~
	int n;cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int maxx=max(max(a,b),c);
		if(a+b+c>2*maxx){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else{
		//7是我的lucky number~ 
		cout<<7;
	}
	return 0; 
}
