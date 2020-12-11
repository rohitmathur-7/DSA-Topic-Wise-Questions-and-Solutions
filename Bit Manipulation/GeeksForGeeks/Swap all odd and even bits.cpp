** QUES - Swap all odd and even bits **

//User function Template for C++
// function to swap odd and even bits
unsigned int swapBits(unsigned int n)
{
   int eve=n&0xAAAAAAAA;
   int odd=n&0x55555555;
   return (eve>>1 | odd<<1);
}

** Explanation - **
int eve = n&0xAAAAAAAA; [We will get all the set even bits.]
int odd = n&0x88888888; [We will get all the set odd bits.]

- Now we just need to right shift eve and left shift odd.
- Now just OR both eve and odd.

** 0xAAAAAAAA - This is a 32 bit number with all even bits set as 1 and all other bits set as 0.
** 0x55555555 - This is a 32 bit number with all odd bits set as 1 and all other bits set as 0.


