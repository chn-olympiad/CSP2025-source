#include<bits/stdc++.h>
using namespace std;
int a,s[50005],l_l[50005],da;
void ll(int c,int h,int k){
	cout<<c<<" "<<h<<" "<<k<<endl;
	if(c<3){
		for(int z=k+1; z<=a; z++){
			ll(c+1,h+s[z],z);
		}
		return;
	}
	for(int z=k+1; z<=a; z++){
		if(h>s[z]){
			
			if(c>3){
				da++;
				
			}
		}
		ll(c+1,h+s[z],z);
	}
}
bool lk(int aa,int bb){
	return aa>bb;
}
int main(){
	cin>>a;
	for(int z=1; z<=a; z++){
		cin>>s[z];
	}
	sort(s+1,s+1+a,lk);
	ll(1,0,0);
	cout<<da;
	return 0;
} 
/*
5
1 2 3 4 5
*/
