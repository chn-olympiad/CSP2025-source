//SN-j00690 涂智竣 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
string a;
int q[1000005];
bool cmp(int c,int p){
	return c>p;
}
int main(){
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	cin>>a;
	int y=0,w=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'){
			w++;
		}
		if('1'<=a[i] && a[i]<='9'){	
			y++;
			q[y]=char(a[i])-48;	
		}
	}
	sort(q+1,q+y+1,cmp);
	for(int i=1;i<=y;i++){
		cout<<q[i];
	}
	for(int i=1;i<=w;i++){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
