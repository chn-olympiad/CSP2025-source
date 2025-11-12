#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("number.in","r", stdin);
	freopen("number.out", "w", stdout);
	string c;
	cin >> c;
	int w=0;
	int q=0;
	for(int i=0; i<=c.size()-1;i++){
		if(c[i]>='0'&&c[i]<='9'){
			w=(int)c[i]-'0';
			a[q]=w;
			q++;
		}
	}
	sort(a, a+q+1);

	for(int i=q; i>0 ;i--){
		cout << a[i];
	}

	return 0;
}
