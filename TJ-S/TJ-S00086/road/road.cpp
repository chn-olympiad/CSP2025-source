#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct hh{
	int q;
	int r;
	int h;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	hh a[m];
	hh b[k];//
	for(int i=0;i<m;i++){
		cin>>a[i].q>>a[i].r>>a[i].h;
	}
	for(int i=0;i<k;i++){//
		cin>>b[i].q>>b[i].r>>b[i].h;//
	}
	int pay=0;
	for(int i=0;i<m;i++){
		if
		pay+=a[i].h;
	}
	cout<<pay;
	return 0;
}
