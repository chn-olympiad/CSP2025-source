#include<bits/stdc++.h>
using namespace std;
int a[500001];
int l[500001],r[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int s=0;
	long long t;
	for(int i=0;i<n;i++){
		t=a[i];
		if(t==k){
			l[s]=i;
			r[s]=i;
			s++;
			continue;
		}
		for(int j=i+1;j<n;j++){
			t=t xor a[j];
			if(t==k){
				l[s]=i;
				r[s]=j;
				s++;
				break;
			}
		}
	}
	int maxr;
	int max=0;
	long long h=0;
	if(s>0){
		for(int i=0;i<n;i++){
			max=i;
			for(int j=i;j<n;j++){
				if(r[max]>r[j]){
					max=j;
				}
			}
			swap(r[max],r[i]);
			swap(l[max],l[i]);
		}
		maxr=r[0];
		for(int i=1;i<s;i++){
			if(l[i]>maxr){
				h++;
				maxr=r[i];
			}
		}
		h++;
		printf("%lld",h);
	}
	else{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
