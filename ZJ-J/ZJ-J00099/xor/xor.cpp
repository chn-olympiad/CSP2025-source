#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500100];
bool lastIndex[500100];

bool isXor(int l,int r) {
	int ans=a[l];
	for(int i=l+1; i<=r; i++) {
		ans^=a[i];
	}
	if(ans==k) {
		return 1;
	}
	return 0;
}
bool isInArea(int l,int r) {
	for(int i=l; i<=r; i++) {
		if(lastIndex[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	int index=0;
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			if(isXor(i,j)&&isInArea(i,j)) {
				for(int q=i; q<=j; q++) {
					lastIndex[q]=1;
				}
				index++;
			}
		}
	}
	cout<<index<<endl;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
