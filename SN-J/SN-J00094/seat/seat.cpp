# include <bits/stdc++.h>
using namespace std;
int a,b,s[100],seat,x,y;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b;
	int k=a*b;
	k--;
	for(int i=0;i<=k;i++){
		cin>>s[i];
	}
	int r=s[0];
	sort(s,s+k+1,cmp);
	for(int i=0;i<=k+1;i++){
		if(s[i]==r){
			seat=i+1;
			break;
		}
	}
	double n=seat,m=a;
	if(n/m==int(seat/a)){
		y=(int)seat/a;
	}
	else y=((int)seat/a)+1;
	int c=(y-1)*a;
	if(y%2==0){
		x=(a+1)-seat%a;
	}
	else{
		x=seat-c;
	}
	cout<<y<<" "<<x;
	// 2025-11-1 11:30
	return 0;
}
