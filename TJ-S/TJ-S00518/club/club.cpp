#include<bits/stdc++.h>
using namespace std;
int a,n,m,s,e,b,l;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>n;
		l=0;
		for(int j=0;j<n;j++){
			cin>>m>>s>>e;
			b=m;
			if(s>b)	b=s;
			if(e>b) b=e;
			if(s=b) b=s;
			if(e=b) b=e;
			l+=b;
		}
		cout<<l<<endl;
	}
	
	return 0;
} 
