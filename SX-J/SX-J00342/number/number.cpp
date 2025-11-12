#include<bits/stdc++.h>;
using namespace std;

char s[1000001];
int a[1000001];
int ans[1000001];

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int l=strlen(s);
	int x=0;
    for(int i=0;i<l;i++){
		a[i]=s[i]-'0';
		if(a[i]>=0&&a[i]<=9){
			x++;
			ans[x]=a[i];
		}
	}
	for(int i=1;i<x;i++){
		for(int j=i+1;j<=x;j++){
			if(ans[j]>ans[i]){
				int t=ans[j];
				ans[j]=ans[i];
				ans[i]=t;
			}
		}
	}
	for(int i=1;i<=x;i++){
		printf("%d",ans[i]);
	}



	return 0;
}