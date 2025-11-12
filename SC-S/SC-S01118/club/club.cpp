#include<bits/stdc++.h> 
#include<cstring> 
#include<iostream> 
unsigned long long q=0,w=0,e=0;
int a[100000][3],s[3];
using namespace std;
void Q(int h,int j){
	if(h==w+1||s[0]>(w/2)||s[1]>(w/2)||s[2]>(w/2)){
		return;
	}
	if(j>e){
		e=j;
	}
	s[0]++;
	Q(h+1,j+a[h][0]);
	s[0]--;
	s[1]++;
	Q(h+1,j+a[h][1]);
	s[1]--;
	s[2]++;
	Q(h+1,j+a[h][2]);
	s[2]--;
	return;
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin>>q;
	for(int z=0;z<q;z++){
		cin>>w;
		for(int x=0;x<w;x++){
			for(int c=0;c<3;c++){
				cin>>a[x][c];
			}
		}
		e=0;
		s[0]=0;
		s[1]=0;
		s[2]=0;
		Q(0,0);
		cout<<e<<"\n";
	}
	return 0;
}