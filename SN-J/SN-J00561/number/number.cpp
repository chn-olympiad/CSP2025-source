#include<bits/stdc++.h>
string namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int len=s.length;
	int a[1001]={},ans=0,n=0;
	for(int j=1;j<=len;j++){
		if(s[j]>=0||s[j]<=9){
			ans++;
			a[ans]=s[j];
		}
	}
	for(int i=1;i<=ans;i++){
		for(int j=1;j<=ans;j++){
			if(a[j]>a[i]){
				n=a[j];
				a[j]=a[i];
				a[i]=n;
			}
		}
	}
	for(int i=1;i<=ans;i++){
		cout<<a[i];
	}
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
