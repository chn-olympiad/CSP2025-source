#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ta;
			scanf("%d",&ta);
			a.push_back(ta);
		}
	}
	int R=a[0];
	sort(a.begin(),a.end(),&cmp);
	int pos=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==R){
			pos=i+1;
			break;	
		}
	}
	int ca=ceil(float(pos)/n);
	int ro=0;
	if(ca%2==1){
		if(pos%n==0) ro=n;
		else ro=pos%n;
	}
	else{
		if(pos%n==0) ro=1;
		else ro=n-pos%n+1;
	}
	printf("%d %d",ca,ro);
	return 0;
}