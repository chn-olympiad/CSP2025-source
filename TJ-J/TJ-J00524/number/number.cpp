#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	short n[1000001];

	cin>>a;
	int i=0;
	int x=0;
	for(i=0;a[i]!=0;i++){
		if(a[i]<=57&&a[i]>=47){n[x]=a[i]-48;
		x++;
			
		}
		
	}

	for(i=0;i<x;i++){
		int m=-1;
		int v=-1;
		int q;
		for(q=0;q<x;q++){
			if(n[q]>m&&n[q]<10){
				m=n[q];
				v=q;
			}
		
		}
		n[v]=11;
		if(m>=0)cout<<m;
	}
	return 0;
}
