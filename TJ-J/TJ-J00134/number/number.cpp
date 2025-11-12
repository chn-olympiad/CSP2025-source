#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<char>b;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b.push_back(a[i]);
			
		}
	}
	
	for(int i=0;i<b.size();i++){
		
		cout<<b[i];
		
	}

	
	
	return 0;
}
