#include<bits/stdc++.h>

 using namespace std;



 const int N =1e9+7, M = 1e3+9, OO = 0x3f3f3f3f;
 const double EPS = 0.0000001;
int num;
std::vector<int> v;
void push_s(long long num)
{
  if(num>N)
{return;}

if(num){ v.push_back(num);}

push_s(num*10+4);
push_s(num*10+7);


}


 int main()
 {

    int n ;

    cin >> n ;
   push_s(0);

   sort(v.begin(),v.end());

   for (int i = 0; i < int (v.size()); i++) {
     /* code */
     if (v[i] == n)
       {
           printf("%d\n" , i + 1) ;
           return 0 ;
       }
   }



}


 // __builtin_popcount(n)<<"\n";









/*
*/
