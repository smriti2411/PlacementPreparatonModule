string returnString(int n, string s){
   string rs = "";
   int count = 0;
   while(n){
       if(n & 1) {
           rs += s[count];
       }
       n = n>>1;
       ++count;
   }
   return rs;
}

vector<string> AllPossibleStrings(string s){
   
   int n = s.length();
   int ns = 1;
   
   for(int i=0; i<n; i++){
       ns = ns<<1;
   }

   ns = ns-1;
   vector<string> vs;
   
   for(int i=1; i<=ns; i++){
       vs.push_back(returnString(i,s));
   }

   sort(vs.begin(), vs.end());
return vs;
     
}