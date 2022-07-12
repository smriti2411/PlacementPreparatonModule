int maxLen(int arr[] , int n)
   {
       HashMap <Integer,Integer> map = new HashMap<> ();
       int pre_sum = 0; int maxlen =0; 
       int i = -1;
       map.put (0,i); 
       i =0; 
       while (i< n){
           pre_sum += arr[i];
           if(!map.containsKey(pre_sum))
               map.put(pre_sum,i);
           else{
               int len = i - map.get(pre_sum);
               if(len>maxlen)
                   maxlen = len ;
           }
           i++;
       }
       return maxlen;
   }