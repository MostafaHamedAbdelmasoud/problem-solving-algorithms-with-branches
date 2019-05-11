#include<bits/stdc++.h>

 using namespace std;



 const int N =20, M = 1e3+9, OO = 0x3f3f3f3f;
 const double EPS = 0.0000001;
 int isON (int c , int p)
 {
    if (c & (1<<(p)))
     {
      return 1;
      /* code */
    }
    else
    return 0;
 }


 int main(){
 int n,h=0,l,r,x,t,sum,k=0,mx,mn;

std::cin >> n;
bool yup=0;
int arr[N];
std::vector<int> v(N);
std::vector<int> vec(N);
  std::cin >> l;
  std::cin >> r;
  std::cin >> x;
  for (int i = 0; i < n; i++) {
    // scanf("%d ",arr+i );
    std::cin >> arr[i];
  }

  for (int i = 1; i < (1<<n); i++) {
     sum=0;
     mx=0;
     mn=1e9;
    for (int j = 0; j < n; j++) {
        if (isON(i , j))
         {
          sum+= arr[j];
          // v.push_back(arr[j]);
          // h++;

          if(mx<arr[j])
          {
                mx=arr[j];
          }
          if(mn>arr[j])
          {
                mn=arr[j];
          }


        }

    }



    if(sum <= r && sum >=l && mx-mn>=x )
    {


      h++;


    }
  }

  std::cout << h << '\n';
  return 0;
}


 // __builtin_popcount(n)<<"\n";




// 29 mahmoud sedeek street forked from misr helwan agricultural, maadi, cairo, egypt






/*
*/
