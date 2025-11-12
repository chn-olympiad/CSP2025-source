//SN-J00427 强立琨 西安市交大附中浐灞右岸学校 
#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000100];
int l=1;
int m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	l=1;
	m=a.size();
	for(int i=0;i<m;i++){
		if(a[i]>='0' && a[i]<='9'){
			b[l]=a[i]-'0';
			l++;
		}
	}
	sort(b+1,b+l,cmp);
	for(int i=1;i<l;i++){
		cout<<b[i];
	} 
	return 0;
}
