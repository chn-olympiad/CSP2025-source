#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	string a;
	cin >> a;
	int f,e;
	int num=0;
	int b[10000]={0};
	for(int i=0; i<=a.size(); i++){
		if(a[i]>='0' && a[i]<='9'){
			f=i;

		}
	}

	int q=0;
	for(int i=0; i<=a.size(); i++){
		if(a[i]>='0' && a[i]<='9'){
			b[q]=a[i];
			num++;
			q++;
		}
	}
	sort(b,b+num);
	for(int i=f; i>=0; i--){
		cout << (char)b[i];
	}
	return 0;
}