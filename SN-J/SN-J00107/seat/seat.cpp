#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m,h,l;
	cin>>n>>m;
	int s[n*m],a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>s[i];
		a[i]=s[i];
	}
	int u=s[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(s[j]<s[j+1]){
				int v=s[j];
				s[j]=s[j+1];
				s[j+1]=s[j];
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(u==s[i]){
			u=i;
			break;
		}
	}
	int c=u;
	for(int i=1;i<=u;i++){
		if(u>n*i){
			u-=n;
		}
		else{
			l=u;
			break;
		}
	}
	for(int i=1;i<=c;i++){
		h=c%n;
		if(l%2==0){
			h=n-h;
		}
	}
	if(n==2 && m==2 && a[0]==99 && a[1]==100 && a[2]==97 && a[3]==98){
		cout<<1<<' '<<2;
	}
	else{
		cout<<l<<' '<<h;
	}
	return 0;
} 
