#include <bits/stdc++.h>
using namespace std;
int main()
{
   char str[101];
   gets(str);
   char s[] = "AEIOUY";
   char *token;
   int mx = 0;

   token = strtok(str, s);
   string tmp;
   while( token != NULL )
   {
      tmp = token;

      if(mx<tmp.size())mx=tmp.size();

      token = strtok(NULL, s);
   }

   cout << mx+1 << endl;

   return(0);
}
