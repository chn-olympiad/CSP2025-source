#include<bits/stdc++.h>
using namespace std;

int a[1000010],n=0;

bool cmp(int a,int b){return a>b;}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char f;
	while(cin>>f){
		if(f>='0' && f<='9'){
			n++;
			a[n]=f-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
}