#include<iostream>bits/stdc++.h
using namespace std;
int main(){
	int n,m,k,q=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			cin>>i>>j;
			if(m<(n-1))
			{
				if(i>j)
				q+=j;
				else q+=i;
			}
		}
	}
	cout<<q;
	cout<<13;
	return 0;
}
