#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);		
	int n,t;	
	cin>>t;
	for(int s=0;s<t;s++){
		int a[100000],b[100000],c[100000];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
		}
		sort(a,a+n+1,cmp);
		sort(b,b+n+1,cmp);
		sort(c,c+n+1,cmp);
		int q=0,w=0,e=0;
		for(int i=1;i<=n/2;i++){
			q+=a[i];
			w+=b[i];
			e+=c[i];
		}
		cout<<q+w+e<<endl;
	}
	
	return 0;
} 
