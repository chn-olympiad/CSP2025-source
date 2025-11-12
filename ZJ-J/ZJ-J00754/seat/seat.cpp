#include<bits/stdc++.h>
using namespace std;
int a,b,c[12000],d,e,m=1,n=1;
void answer(int x,int y,int z){
	if(z==0){
		for(int i=1; i<=a; i++){
			if(e==d) break;
			else{
				e--;
				m++;
			}
		}
		m--;n++;
		answer(m,n,1);
	}
	else{
		for(int i=a; i>=1; i--){
			if(e==d) break;
			else{
				e--;
				m--;
			}
		}
		m++;n++;
		answer(m,n,0);		
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	e=a*b;
	for(int i=1; i<=a*b; i++){
		cin>>c[i];
	}
	sort(c+2,c+1+a*b);
	for(int i=1; i<=a*b; i++){
		if(c[i]>c[1]){
			d=a*b-i+2;
			break;
		}
	}
	answer(1,1,1);
	cout<<n<<" "<<m;
	return 0;
}

