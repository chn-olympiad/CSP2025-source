#include<bits/stdc++.h>
#include<stdio.h>
using namespace std; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[102]={0};
	cin >> n >> m;
	int s=n*m;
	int maxx=1;
	for(int i=0;i<s;i++){
		cin >> a[i];
		if(i!=0&&a[i]>a[0]){
			maxx++;
		}
	}
	int f=maxx/n;
	if(maxx%n==0){
		if(f%2==0){
			cout << f << " " << 1;
		}
		else if(f%2==1){
			cout << f << " " << n;
		}
	}
	else if(maxx%n!=0){
		f++;
		int g=maxx%n;
		if(f%2==0){
			cout << f << " " << n-g+1;
		}
		else if(f%2==1){
			cout << f << " " << g;
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
