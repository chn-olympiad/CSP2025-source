#include<bits/stdc++.h>
using namespace std;
char ch;
int a[1000005],i=0;
bool cmp(int aa,int bb){
	return aa>bb; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin.get(ch)){
		if(ch>='0'&&ch<='9')a[++i]=ch-'0';
	}
	sort(a+1,a+i+1,cmp);
	for(int j=1;j<=i;j++){
		printf("%d",a[j]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
