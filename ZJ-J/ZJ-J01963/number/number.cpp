//#Shang4Shan3Ruo6Shui4
//1
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	int b[10]={0},f=1;
	cin>>a;
	int l=strlen(a);
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9')b[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(b[i]&&i!=0)f=0;
		if(i==0){
			if(f)cout<<0;
			else{
				for(int j=0;j<b[0];j++)cout<<0;
			}
		}
		else{
			for(int j=0;j<b[i];j++)cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
