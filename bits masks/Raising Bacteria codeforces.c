#include<bits/stdc++.h>

 using namespace std;



 const int N =1e9+7, M = 1e3+9, OO = 0x3f3f3f3f;
 const double EPS = 0.0000001;
int num;
std::vector<int> v;
void push_s(long long num);




 int main()
 {

    long long n ;
num=0;
    cin >> n ;


while(n>0)
{


    if(n%2 == 1)
    {
    num+=1;
    }
      n/=2;
}
std::cout << num << '\n';
return 0;

}


 // __builtin_popcount(n)<<"\n";





/*
*/
