#include<bits/stdc++.h>
using namespace std;
string a;
int f[1000005],max1=INT_MIN,x=1;
int len1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len1=a.size();
	for(int i=0;i<=len1-1;i++){
		if(a[i]=='1'){
			f[x]=1;
			x++;
		}
		if(a[i]=='2'){
			f[x]=2;
			x++;
		}
		if(a[i]=='3'){
			f[x]=3;
			x++;
		}
		if(a[i]=='4'){
			f[x]=4;
			x++;
		}
		if(a[i]=='5'){
			f[x]=5;
			x++;
		}
		if(a[i]=='6'){
			f[x]=6;
			x++;
		}
		if(a[i]=='7'){
			f[x]=7;
			x++;
		}
		if(a[i]=='8'){
			f[x]=8;
			x++;
		}
		if(a[i]=='9'){
			f[x]=9;
			x++;
		}
		if(a[i]=='0'){
			f[x]=0;
			x++;
		}
	}
	x--;
	sort(f+1,f+x+1);
	for(int i=x;i>=1;i--){
		cout<<f[i];
	}
	return 0;
}
