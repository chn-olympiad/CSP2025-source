#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >>a;
	int len,q=0,w=0,e=0,r=0,t=0,y=0,u=0,s=0,o=0,p=0;
	len=a.size();
	for(int i=0;i<=len;i++){
		if(a[i]=='9'){
			o++;
		}else if(a[i]=='8'){
			s++;
		}else if(a[i]=='7'){
			u++;
		}else if(a[i]=='6'){
			y++;
		}else if(a[i]=='5'){
			t++;
		}else if(a[i]=='4'){
			r++;
		}else if(a[i]=='3'){
			e++;
		}else if(a[i]=='2'){
			w++;
		}else if(a[i]=='1'){
			q++;
		}else if(a[i]=='0'){
			p++;
		}
	}
	for(int i=1;i<=o;i++){
		cout<<'9';
	}for(int i=1;i<=s;i++){
		cout<<'8';
	}for(int i=1;i<=u;i++){
		cout<<'7';
	}for(int i=1;i<=y;i++){
		cout<<'6';
	}for(int i=1;i<=t;i++){
		cout<<'5';
	}for(int i=1;i<=r;i++){
		cout<<'4';
	}for(int i=1;i<=e;i++){
		cout<<'3';
	}for(int i=1;i<=w;i++){
		cout<<'2';
	}for(int i=1;i<=q;i++){
		cout<<'1';
	}for(int i=1;i<=p;i++){
		cout<<'0';
	}
	return 0;
}
