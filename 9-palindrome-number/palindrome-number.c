bool isPalindrome(long x) {
    if(x<0){
        return 0;
    }
     long original=x;
     long reversed=0;
     while(x!=0){
        long digit=x%10;
        reversed=reversed*10+digit;
        x=x/10;
     }
     return original==reversed;
}