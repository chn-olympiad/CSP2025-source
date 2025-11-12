#include<bits/stdc++.h>
#include<cstring>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","z",stdout);
	int b,l,n=0,a[10005];
	char c[10005];
	cin>>c;
	l=strlen(c);
	
	for(int i=0;i<l;i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[n]=c[i]-'0';
			
			n++;
		}
	}
	sort(a,a+n+1,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
} 
