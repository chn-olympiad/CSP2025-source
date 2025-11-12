#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	int ni=1,mi=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			cout<<mi<<" "<<ni;
			break;
		}
		if(mi%2==1)ni++;
		else ni--;
		if(ni>n||ni<1){
			if(mi%2==1)ni=n;
			else ni=1;
			mi++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
