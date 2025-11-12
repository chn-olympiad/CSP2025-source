
/*
* employ.cpp
* 
* Copyright 2025 Administrator <Administrator@S16202-C50>
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
* MA 02110-1301, USA.
* 
* 
*/
/*
* employ.cpp
* 
* Copyright 2025 Administrator <Administrator@S16202-C50>
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
* MA 02110-1301, USA.
* 
* 
*/
/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
* MA 02110-1301, USA.
* 
*/

//#include <bitset>

#include <fstream>
#include <string>
using namespace std;
int a,b;
int c[550];
bool d[550];
string g;
ifstream fin("employ.in");
ofstream fout("employ.out");
int f(int e,int h,int j){
fout<<"f("<<e<<','<<h<<','<<j<<')'<<endl;
if(e>a){
// fout<<"ret0";
return 0;
}
if(h>=b){
// fout<<"ret";
return 1/*<<(a-e-1)*/;
}
long long k=0;

for(int i = 0;i<a;i++){
if(!d[i]){
bool l=g[e]=='1';
// fout<//<l;
if(c[i]<=j){
l=0;
}
// fout<</c[i];
d[i]=1;
k+=f(e+1,h+l,j+!l);
d[i]=0;
k%=998244353;
}
}
return k;
}
int main(void){

fin>>a>>b>>g;
int i=a;
while(i--){
fin>>c[i];
}
long long k=0;
bool l=g[0]=='1';
for(int i = 0;i<a;i++){
if(!d[i]){
d[i]=1;
k+=f(0,l,!l);
d[i]=0;
k%=998244353;
}
}
fout<<k;
return 0;
}
