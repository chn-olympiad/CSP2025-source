#include <bits/stdc++.h>
using namespace std;
int a,b[100010],c[100010],d[100010];
int main(){
	cin>>a;
	int e=0;
	for(int i=0;i<a-1;i++)
	{
	cin>>b[i]>>c[i]>>d[i];
	e+=d[i];
	}
	cout<<e;
} 
