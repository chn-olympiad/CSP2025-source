#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000005];
int c[1000005],d,e[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			b[i]=a[i];
			c[n]=b[i]-'0';
			n++;
		}
	}
	int max=0;
	for(int q=0;q<n;q++){
		for(int i=0;i<n;i++){
			if(c[i]>max){
				max=c[i];
			}
		}
		e[q]=max;
		for(int j=0;j<n;j++){
			if(c[j]==max){
				c[j]=0;
				break;
			}
		}
		max=0;
	}
	for(int i=0;i<n;i++){
		cout<<e[i];
	}
	return 0;
}
