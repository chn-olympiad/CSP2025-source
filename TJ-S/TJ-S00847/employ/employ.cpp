#include<bits/stdc++.h>
using namespace std;
string a;
int d[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int c,b,e=100000,f=0;
	cin>>b>>c;
	cin>>a;
	for(int i=0;i<b;i++){
		cin>>d[i];
	}
	for(int i=0;i<b;i++){
		if(a[i]==0&&i<e){
			e=i;
		}
	}
	for(int i=0;i<b;i++){
		if(d[i]>=d[e]){
			f++;
		}
	}
	int z=1,y=1;
	for(int i=0;i<b-1;i++){
		y=y*z;
		z++;
	}
	cout<<y*f;
	return 0;
}
