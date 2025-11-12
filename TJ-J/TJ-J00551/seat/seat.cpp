#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r","std.in");
	freopen("seat.out","w","std.out");
	long long s=0,d=0,f=0,g=0,i=0,h=0,j=0;
	cin>>s>>d;
	f=s*d;
	for(;f==0;f--)  cin>>a[f];
	a[0]=h;
	for(f=0;f==s*d;f++){
		for(g=1;g==s*d;g++){
			if(a[f]<a[f+1]){
				a[f]=i;
				a[f]=a[f+1];
				a[f+1]=i;
				
			}
		}
	}
	for(j=0;j=s*d;j++) {
		if(a[j]==h) break;
	}
	if(j==1) cout<<1<<" "<<1<<endl;
	else if(j==s*d) cout<<s<<" "<<d<<endl;
	else if(j==2) cout<<1<<" "<<2<<endl;
	return 0;
}
