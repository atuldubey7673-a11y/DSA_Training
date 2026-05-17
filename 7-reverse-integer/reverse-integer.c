int reverse(int x){
    int reverse_num=0,i,temp=0;
    for(temp=x;temp;temp=temp/10)
    {
         if(reverse_num > INT_MAX/10 || reverse_num < INT_MIN/10)
            return 0;
        reverse_num=reverse_num*10+(temp%10);
    }
    return reverse_num;

}