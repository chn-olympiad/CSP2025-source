#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10010],l=0,p=0;
	int d=0,e=0,f=0,r=0,t=0,y=0,u=0,o=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			if(p<1){
			
			a[l]=1;
			l=l+1;
			p=p+1;
				 
		}
		}
		if(s[i]=='2'){
			if(d<1){
			
			a[l]=2;
			l=l+1;
			d=d+1; 
		}
		}
		if(s[i]=='3'){
		if(e<1){
			a[l]=3;
			l=l+1;
			e=e+1; 
		}
		}
		if(s[i]=='4'){
		if(f<1){
			a[l]=4;
			l=l+1;
			f=f+1;
		}
		}
		if(s[i]=='5'){
		if(r<1){
			
			a[l]=5;
			l=l+1;
			r=r+1;
		}
		}
		if(s[i]=='6'){
		if(t<1){
			a[l]=6;
			l=l+1;
			t=t+1;
		}
		}
		if(s[i]=='7'){
			if(y<1){
			
			a[l]=7;
			l=l+1;
			y=y+1;
		}
		}
		if(s[i]=='8'){
			if(u<1){
			
			a[l]=8;
			l=l+1;
			u=u+1;
		}
		}
		if(s[i]=='9'){
			if(o<1){
	 
			a[l]=9;
			l=l+1;
			o=o+1;
		}
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){

			cout<<a[i];
			
	}
	return 0;
}
