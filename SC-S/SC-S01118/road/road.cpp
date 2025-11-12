#include<bits/stdc++.h> 
#include<cstring> 
#include<iostream> 
int q=0,w=0,e=0,r=0,t=0,y=0,u=0;
int a[10000][10000],s[10000];
using namespace std;
int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	cin>>q>>w>>e;
	for(int z=0;z<w;z++){
		cin>>r>>t>>y;
		a[r][t]=y;
		a[t][r]=y;
		u+=y;
	}
	for(int z=w;z<e+w;z++){
		cin>>s[z];
		for(int z=0;z<q;z++){
			cin>>r;
			a[z][q]=r;
			a[q][z]=r;
		}
	}
	cout<<u;
	return 0;
}