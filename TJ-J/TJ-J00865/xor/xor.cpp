#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    int n,k;
    cin >> n >> k;
    int a[n];
    int l[n],r[n],c=0;
    for(int i = 0;i < n;i++){
    	cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		int d = a[i];
		for(int j = i;j < n;j++){
			for(int f = i+1;f < j;i++){
				d = d^a[i];
			}
			if(d==k){
				l[c] = i;
				r[c] = j;
				c++;
			}
		}
	}
	int num=0;
	for(int i = 0;i < c-1;i++){
		if(r[i]<l[i+1]){
			num++;
		}
	}
	cout << num;
}
