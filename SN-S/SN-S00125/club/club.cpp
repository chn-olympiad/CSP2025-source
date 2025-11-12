#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
struct student{
	int c1;
	int c2;
	int c3;
	int maxl;
	int maxll;
	int maxlll;
}a[N];

int club1,club2,club3;

bool cmp(student a,student b){
	return a.c1 > b.c1;
}

bool cmp2(student a,student b){
	return a.c2 > b.c2;
}

bool cmp3(student a,student b){
	return a.c3 > b.c3;
}

bool cmp1(student a,student b){
	return a.maxl > b.maxl;
}

int find_max(int a,int b,int c){
	int qwq = max(max(a,b),max(b,c));
	if(qwq == a) return 1;
	if(qwq == b) return 2;
	if(qwq == c) return 3;
}

int find_maxl(int a,int b,int c){
	int qwq = max(max(a,b),max(b,c));
	int qoq = min(min(a,b),min(a,b));
	int qaq = a + b + c - qwq - qoq;
	if(qaq == a) return 1;
	if(qaq == b) return 2;
	if(qaq == c) return 3;
}

int maxx;
int total;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int p = 1;p<=t;p++){
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			a[i].maxl = find_max(a[i].c1,a[i].c2,a[i].c3);
		}
		if(n == 2){
			for(int i = 1;i<=2;i++){
				total = a[i].c1 + a[i+1].c2;
				maxx = max(maxx,total);
				total = a[i].c1 + a[i+1].c3;
				maxx = max(maxx,total);
				total = a[i].c2 + a[i+1].c1;
				maxx = max(maxx,total);
				total = a[i].c2 + a[i+1].c3;
				maxx = max(maxx,total);
				total = a[i].c3 + a[i+1].c1;
				maxx = max(maxx,total);
				total = a[i].c3 + a[i+1].c2;
				maxx = max(maxx,total);
			}
			//cout<<"\n";
			cout<<maxx<<"\n";
		}
		int totaly = 0;
		if(n!=2){
			if(a[2].c2 == 0 && a[2].c3 == 0){
				sort(a+1,a+n+1,cmp);
				for(int i = 1;i<=n/2;i++){
					totaly += a[i].c1; 
				}
				cout<<totaly<<"\n";
			}
			else if(a[2].c1 == 0 && a[2].c3 == 0){
				sort(a+1,a+n+1,cmp2);
				for(int i = 1;i<=n/2;i++){
					totaly += a[i].c2; 
				}
				cout<<totaly<<"\n";
			}
			else if(a[2].c1 == 0 && a[2].c2 == 0){
				sort(a+1,a+n+1,cmp3);
				for(int i = 1;i<=n/2;i++){
					totaly += a[i].c3; 
				}
				cout<<totaly<<"\n";
			}
			else{
				sort(a+1,a+n+1,cmp1);
				for(int i = 1;i<=n;i++){
					if(a[i].maxl == 1){
						if(club1 ==n/2){
							if(club2 == n/2){
								totaly+=min(a[i].c2,a[i].c3);
							}
							else{
								totaly+=max(a[i].c2,a[i].c3);
							}
							if(find_maxl(a[i].c1,a[i].c2,a[i].c3) == 2) club2++;
							if(find_maxl(a[i].c1,a[i].c2,a[i].c3) == 3) club3++;
						}
						else{
							totaly+=a[i].c1;
							club1++;	
						}
					}
					if(a[i].maxl == 2){
						if(club2 ==n/2){
							if(club3 == n/2){
								totaly+=min(a[i].c1,a[i].c3);
							}
							else{
								totaly+=max(a[i].c1,a[i].c3);
							}
							if(find_maxl(a[i].c1,a[i].c2,a[i].c3) == 1) club1++;
							if(find_maxl(a[i].c1,a[i].c2,a[i].c3) == 3) club3++;
						}
						else{
							totaly+=a[i].c2;
							club2++;	
						}
					}
					if(a[i].maxl == 3){
						if(club3 ==n/2){
							if(club1 == n/2){
								totaly+=min(a[i].c1,a[i].c2);
							}
							else{
								totaly+=max(a[i].c1,a[i].c2);
							}
							if(find_maxl(a[i].c1,a[i].c2,a[i].c3) == 1) club1++;
							if(find_maxl(a[i].c1,a[i].c2,a[i].c3) == 2) club2++;
						}
						else{
							totaly+=a[i].c3;
							club3++;	
						}
					}
				}
				cout<<totaly<<"\n";
			}
		}
	}
}
