//SN-J01140 西安高新第二初级中学 韦博彦 仅用十分钟就做出了这道题，啊~好骄傲 
#include<bits/stdc++.h>
using namespace std;
int p[1000002],l=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			p[++l]=a[i]-'0';
		}
	}
	sort(p+1,p+1+n,cmp);
	if(p[1]==0){
		cout<<0;
	}else{
		for(int i=1;i<=l;i++){
			cout<<p[i];	
		}
	}
	
	
	
	return 0;
}
