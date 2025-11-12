#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
string k;
char f[N],g[N],Max=48;
long long a,b,c,q=1,r=1,s=1,t=1,u=1,v=1,w=1,x=1,y=1,z=1;
long long v9[N],v8[N],v7[N],v6[N],v5[N],v4[N],v3[N],v2[N],v1[N],v0[N];
int main(){
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	for(int i=1;i<=10000;i++){
		cin>>f[N];
		if(f[i]=='9'){
			v9[q];q+=1;
		}else if(f[i]=='8'){
			v8[r];r+=1;
		}else if(f[i]=='7'){
			v7[s];s+=1;
		}else if(f[i]=='6'){
			v6[t];t+=1;
		}else if(f[i]=='5'){
			v5[u];u+=1;
		}else if(f[i]=='4'){
			v4[v];v+=1;
		}else if(f[i]=='3'){
			v3[w];w+=1;
		}else if(f[i]=='2'){
			v2[x];x+=1;
		}else if(f[i]=='1'){
			v1[y];y+=1;
		}else if(f[i]=='0'){
			v0[z];z+=1;
		}
	}for(int i=1;i<=u;i++){
		if(v9[i]==0){
			break;
		}cout<<v9[i];
	}for(int i=1;i<=u;i++){
		if(v8[i]==0){
			break;
		}cout<<v8[i];
	}for(int i=1;i<=u;i++){
		if(v7[i]==0){
			break;
		}cout<<v7[i];
	}for(int i=1;i<=u;i++){
		if(v6[i]==0){
			break;
		}cout<<v6[i];
	}for(int i=1;i<=u;i++){
		if(v5[i]==0){
			break;
		}cout<<v5[i];
	}for(int i=1;i<=u;i++){
		if(v4[i]==0){
			break;
		}cout<<v4[i];
	}for(int i=1;i<=u;i++){
		if(v3[i]==0){
			break;
		}cout<<v3[i];
	}for(int i=1;i<=u;i++){
		if(v2[i]==0){
			break;
		}cout<<v2[i];
	}for(int i=1;i<=u;i++){
		if(v1[i]==0){
			break;
		}cout<<v1[i];
	}for(int i=1;i<=u;i++){
		if(v0[i]==0){
			break;
		}cout<<v0[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
