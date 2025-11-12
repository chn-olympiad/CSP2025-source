#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	if(n==1&m==1){
		cout<<a[1];
	}
	int q=a[1];
	sort(a,a+n+1);
	for(int i=1;i<=105;i++){
		if(a[i]==q){
			q=i;
			break;
		}
	}
    if(q<=n){
       	cout<<q<<" "<<'1';
	}else if(q>n&&q<=2*n){
		cout<<2*n-q<<" "<<'2';
	}else if(q>2*n&&q<=3*n){
		cout<<q-2*n<<" "<<'3';
	}else if(q>3*n&&q<=4*n){
		cout<<4*n-q<<" "<<'4';
	}else if(q>4*n&&q<=5*n){
		cout<<q-4*n<<" "<<'5';
	}else if(q>5*n&&q<=6*n){
		cout<<6*n-q<<" "<<'6';
	}else if(q>6*n&&q<=7*n){
		cout<<q-6*n<<" "<<'7';
	}else if(q>7*n&&q<=8*n){
		cout<<8*n-q<<" "<<'8';
	}else if(q>8*n&&q<=9*n){
		cout<<q-8*n<<" "<<'9';
	}else if(q>9*n&&q<=10*n){
		cout<<10*n-q<<" "<<"10";
	}
	return 0;
}
