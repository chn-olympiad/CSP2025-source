#include<bits/stdc++.h>
using namespace std;
string a;
string c="";
long long n,b[100005],j=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<strlen(a);i++){
		if(a[i]>='0' && a[i]<='9'){
			b[j]=int(a[i]);
			n++;
			j++;
		}
		
	}
	sort(b+1,b+n+1,cmp);
	for(long long i=1;i<=n;i++){
		c=c+char(b[i]);
	}
	cout<<c;
	return 0;
} 
