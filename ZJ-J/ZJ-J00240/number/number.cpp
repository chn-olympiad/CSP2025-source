#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string c;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>c;
	int z=1,len=c.size();
	for(int i=0;i<len;i++){
		if(c[i]=='0'){
			a[z]=0;
			z++;
		}else{
			if(c[i]=='1'){
			a[z]=1;
			z++;
		}else{
			if(c[i]=='2'){
			a[z]=2;
			z++;
		}else{
			if(c[i]=='3'){
			a[z]=3;
			z++;
		}else{
			if(c[i]=='4'){
			a[z]=4;
			z++;
		}else{
			if(c[i]=='5'){
			a[z]=5;
			z++;
		}else{
			if(c[i]=='6'){
			a[z]=6;
			z++;
		}else{
			if(c[i]=='7'){
			a[z]=7;
			z++;
		}else{
			if(c[i]=='8'){
			a[z]=8;
			z++;
		}else{
			if(c[i]=='9'){
			a[z]=9;
			z++;
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
	}	
	sort(a,a+z);
	
	for(int i=z-1;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}