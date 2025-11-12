#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a,b;
	cin>>a;
	b=a;
	int count=1;
	while(b>9){
		b=b/10;
		count++;
	} 
	int c[count];
	for(int q=0;q<count;q++){
		c[q]=a%10;
		a=a/10;
	}
	for(int q=0;q<count;q++){
		for(int w=q+1;w<count;w++){
			if(c[w]>c[q]){
				int zhou=c[q];
				c[q]=c[w];
				c[w]=zhou;
			}
		}
	}
	int result=0,zhou=1;
	for(int q=0;q<count;q++){
		for(int w=q+1;w<count;w++){
			zhou=zhou*10;
		}
		result=result+c[q]*zhou;
		zhou=1;
	}
	cout<<result;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
