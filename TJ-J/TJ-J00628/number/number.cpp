#include<iostream> 
#include<string> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a[100010];
	string n[100010];
	int b=1;
	for(int i=1;i<=100010;i++){
		cin>>a[i];
	}for(int i=1;i<=100010;i++){
		if(a[i]<="9" && a[i]>="0"){
		    n[b]=a[i];
		    b++;
		}
		
	}
	for(int i=1;i<=b;i++){
		for(int j=i;j<=b;j++){
			if(n[i]<n[j]){
				string c=n[i];
				n[i]=n[j];
				n[j]=c;
			}
		}
	}for(int i=1;i<=b;i++){
		cout<<n[i];
	}
	return 0;
}
