#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[1000000]={0};
    int a[100]={0};
    for(int i=0;i<=1000000;i++){
    	cin >> s[i];
	}
	for(int i=0;i<=1000000;i++){
		if(s[i]>='1'||s[i]<='0'){
			int b=0;
			a[b]=s[i];
			b++;
	    }
    }
	int c[100]={0};
	int d[100]={0};
	int e[100]={0};
	int f[100]={0};
	int g[100]={0};
	int h[100]={0};
	int k[100]={0};
	int t[100]={0};
	int r[100]={0};
	int y[100]={0};
	for(int i=0;i<=100;i++){
		if(a[i]='9')c[i]=a[i];
		if(a[i]='8')d[i]=a[i];
		if(a[i]='7')e[i]=a[i];
		if(a[i]='6')f[i]=a[i];
		if(a[i]='5')g[i]=a[i];
		if(a[i]='4')h[i]=a[i];
		if(a[i]='3')k[i]=a[i];
		if(a[i]='2')t[i]=a[i];
		if(a[i]='1')r[i]=a[i];
		if(a[i]='0')y[i]=a[i];
    }
    for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	for(int i=0;i<=100;i++){
        cout << c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
