#include <bits/stdc++.h>

using namespace std;

int n,m,c,r,grade[105],m_grade,pos;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> grade[i];
	}
	m_grade = grade[1];
	sort(grade+1,grade+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(grade[i]==m_grade) pos=i;
	}
	if(pos%n==0){
		c=pos/n;
		if(c%2==0){
			r=1;
		}else{
			r=n;
		}
		cout << c << " " << r;
		return 0;
	}
	if((pos/n+1)%2==0){
		c = pos/n+1;
		r = n-(pos%n)+1;
	}else{
		c = pos/n+1;
		r = pos%n;
	}
	cout << c << " " << r;
	return 0;
}
