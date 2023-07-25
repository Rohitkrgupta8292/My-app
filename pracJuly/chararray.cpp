#include <bits/stdc++.h>
using namespace std;

int main()
{
   //check palindrome..
   int n;
   cout<<"N: ";
   cin>>n;

   char arr[n+1];
   cout<<"Enter the word: ";
   cin>>arr;

   bool check = 1;
   for(int i=0; i<n; i++)
   {
       if(arr[i] != arr[n-1-i])
       {
           check = 0;
           break;
       }
   }

   if(check == true)
   {
      cout<<"The word is Palindrome!\n";
   }
   else
   {
      cout<<"The word is not Palindrome!\n";
   }
   return 0;
}