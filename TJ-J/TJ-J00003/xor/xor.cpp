#include<bits/stdc++.h>
using namespace std;
int js(int a[],int l,int r){
	int num=a[l];
	for(int i=l+1;i<=r;i++){
		num=num^a[i];
	}
	return num;
}
struct pi
{
	int l;
	int r;
	bool visited;
};
vector<pi> vec;int Max=0;
void dfs(int data,vector<pi> ve){
	Max=max(Max,data);
	for(int i=0;i<vec.size();i++){
		if(!vec[i].visited){
			bool f=1;
			for(int j=0;j<ve.size();j++){
				if(!(vec[i].l>ve[j].r || vec[i].r<ve[j].l)){
					f=0;break;
				}
			}
			if(f){
				vec[i].visited=1;
				ve.push_back(vec[i]);
				dfs(data+1,ve);
				ve.pop_back();
				vec[i].visited=0;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int k0=js(a,i,j);
			if(k0==k){
				pi tmp;tmp.l=i;tmp.r=j;tmp.visited=0;
				vec.push_back(tmp);
			}
//			printf("%d^%d:%d-%d\n",i,j,Max,k);
		}
	}
	vector<pi> ve;
	dfs(0,ve);
	printf("%d\n",Max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
